#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int n;
	int tmp;
	int tmpmax = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &tmp);
		tmpmax = max(tmp,tmpmax);
	}
	tmpmax -= 25;
	printf("%d", tmpmax > 0 ? tmpmax : 0);
}