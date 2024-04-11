#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,a,n0,n1,m0,m1;

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a);
		if(a&1)++n1;else ++n0;
	}
	m0=(n-m)/2;
	m1=(n-m)/2;
	if(n==m)
	{
		if(n1&1)printf("Stannis\n");
		else printf("Daenerys\n");
		return 0;
	}
	if((n&1)!=(m&1))
	{
		++m0;
		if(m&1)
		{
			if(n1<=m1)printf("Daenerys\n");
			else printf("Stannis\n");
		}
		else
		{
			if(n1<=m1||n0<=m1)printf("Daenerys\n");
			else printf("Stannis\n");
		}
	}
	else
	{
		if(m&1)
		{
			if(n0<=m0)printf("Stannis\n");
			else printf("Daenerys\n");
		}
		else
		{
			printf("Daenerys\n");
		}
	}
}