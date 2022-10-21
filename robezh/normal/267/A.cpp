#include<cstdio>
#include<iostream>
using namespace std;

int sub(int a, int b){
	if(a == 0 || b == 0) return 0;
	return a / b + sub(b, a%b);
}

int main(){
	int n, a, b;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &a, &b);
		printf("%d\n", sub(a,b));
	}
}