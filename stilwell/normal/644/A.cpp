#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,a,b,A,B,i,j,k,na,nb;
int c[105][105];

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(i=1;i<=a;++i)
	for(j=1;j<=b;++j)
	if((i+j)&1)++B;else ++A;
	na=1;nb=2;
	if(A<B)swap(na,nb);
	for(i=1;i<=a;++i)
	for(j=1;j<=b;++j)
	if((i+j)&1)
	{
		if(nb<=n)c[i][j]=nb;
		nb+=2;
	}
	else
	{
		if(na<=n)c[i][j]=na;
		na+=2;
	}
	if(na<=n||nb<=n)printf("-1\n");
	else
	{
		for(i=1;i<=a;++i)
		{
			for(j=1;j<=b;++j)printf("%d ",c[i][j]);
			printf("\n");
		}
	}
}