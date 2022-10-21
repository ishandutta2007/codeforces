#include<iostream>
#include<cstdio>
using namespace std;

int n;
int rmzero;
int num[300050];
int full[300050];

void updatermzero(){
	while(full[rmzero] == 1){
		rmzero--;
	}
}

int main(){
	scanf("%d", &n);
	rmzero = n-1;
	fill(full,full+n,0);
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	printf("1 ");
	for(int i = 0; i < n; i++){
		full[num[i] - 1] = 1;
		updatermzero();
		printf("%d ", i+3-n+rmzero);
	}
}