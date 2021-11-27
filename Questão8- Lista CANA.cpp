/*. Seja X[1 . . . n] um vetor de números reais. Dizemos que X tem um elemento popular x se
mais de um terço de seus elementos são iguais a x. Escreva um algoritmo de tempo linear Θ(n) que diz
se X possui ou não um elemento popular. Caso sim, devolva o seu valor.*/

//Questão 9
#include <iostream>
#include <cmath>
using namespace std;
 
int getMax(int arr[], int size) {
  int max = arr[0];
  for (int i = 1; i < size; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;
}

void CountingSort(int arr[], int size, int div) {
  int output[size];
  int count[10] = {0};
  for (int i = 0; i < size; i++)
    count[ (arr[i]/div)%10 ]++;
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];
  for (int i = size - 1; i >= 0; i--){
    output[count[ (arr[i]/div)%10 ] - 1] = arr[i];
    count[ (arr[i]/div)%10 ]--;
   }
  for (int i = 0; i < size; i++)
    arr[i] = output[i];
}

void RadixSort(int arr[], int size) {
  int m = getMax(arr, size);
  for (int div = 1; m/div > 0; div *= 10)
    CountingSort(arr, size, div);
}

int popular(int vetor[], int tamanho, int  *p){
  int i, quant;
  float minimo;

  //calcula a quantidade minima de repeticoes.
  minimo = tamanho/3;

  cout << "O limite é: " << minimo << "\n";
  //quantidade de repeticoes do elemento atual;
  quant = 1;

  //ordena os elementos do vetor
  RadixSort(vetor, tamanho);

  for(i=0; i<tamanho-1; i++){
    //se for igual ao proximo
    if(vetor[i] == vetor[i+1]){
      quant++;
    }
    //se nao for igual ao proximo
    else if(vetor[i] != vetor[i+1]){
      quant = 1;
    }
    //se tiver atingido o minimo
    if(quant > minimo){
      //cout << "O valor popular é: " << vetor[i];
		  *p = 1;
      return vetor[i];
    }
  }
  return 0;
}

int main() {
  int vetor[10] = {1,2,5,4,56,98,1,7,8,2};
	int p = 0;
  int res = popular(vetor, 10, &p);

	if(p == 1) {
		cout << "O valor popular é: " << res;
	} else {
		cout << "Não tem valor popular" << endl;
	}
} 
