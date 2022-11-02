#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,n1,n2;

int main()
{
	scanf("%d%d",&m,&n);
	if(m==n+1)
	{
		for(i=1;i<=n;++i)printf("01");
		printf("0");
		return 0;
	}
	if(m==n)
	{
		for(i=1;i<=n;++i)printf("01");
		return 0;
	}
	if(n<m-1||n>2*m+2)
	{
		printf("-1\n");
		return 0;
	}
	if(n>=m+1)n2=n-(m+1);
	n1=n-2*n2;
	for(i=1;i<=m;++i)
	{
		if(n1)printf("1"),--n1;
		else printf("11"),--n2;
		printf("0");
	}
	if(n1)printf("1");
	if(n2)printf("11");
}