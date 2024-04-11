#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;

int main()
{
	scanf("%d%d",&n,&m);
	if(m==n)printf("-1\n");
	else
	{
		m=n-m;
		printf("%d",m);
		for(i=2;i<=m;++i)printf(" %d",i-1);
		for(i=m+1;i<=n;++i)printf(" %d",i);
		printf("\n");
	}
}