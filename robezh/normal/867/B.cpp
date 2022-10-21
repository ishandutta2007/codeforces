#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;



int main(){
	int n;
	scanf("%d", &n);
	if(n == 1) printf("1 1\n1");
	else printf("%d 2\n1 2",(n-1)*2);
	
	return 0;
}