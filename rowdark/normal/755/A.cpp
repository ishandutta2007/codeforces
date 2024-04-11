#include<stdio.h>
int n,m;
int main(){
	scanf("%d",&n);
	if(n<=2) printf("%d\n",n+2);
	else printf("%d\n",n-2);
	return 0;
}