#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;
int a[100005];
char ch;

int main()
{
	scanf("%d",&n);
	if(n==0)
	{
		printf("a\n");
		return 0;
	}
	for(m=1;;++m)
	{
		a[m]=m*(m-1)/2;
		if(a[m]>=n)break;
	}
	ch='a';
	for(i=m;i>=2;--i)
	for(;n>=a[i];n-=a[i])
	{
		for(j=1;j<=i;++j)putchar(ch);
		++ch;
	}
	printf("\n");
}