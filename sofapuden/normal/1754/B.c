#include<stdio.h>
#define MX	105

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		if(n&1){
			printf("%d ", n);
		}
		for(int i = n / 2; i; --i){
			printf("%d %d ", i, i+n/2);
		}
		printf("\n");
	}
}