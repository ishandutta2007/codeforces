#include<stdio.h>
long n,m,i,j;
int main(){
	scanf("%ld%ld%ld",&n,&i,&j),i=n-i,++j;
	printf("%ld\n",i<j?i:j);
	scanf("%ld%ld%ld",&n,&m,&i);
	return 0;
}