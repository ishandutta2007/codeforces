#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k,x,n1,n2,n3;
int num[10];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&x);
		++num[x];
	}
	n1=min(num[1],min(num[2],num[4]));
	num[1]-=n1;num[2]-=n1;num[4]-=n1;
	n2=min(num[1],min(num[2],num[6]));
	num[1]-=n2;num[2]-=n2;num[6]-=n2;
	n3=min(num[1],min(num[3],num[6]));
	num[1]-=n3;num[3]-=n3;num[6]-=n3;
	if(3*(n1+n2+n3)!=n)printf("-1\n");
	else
	{
		for(i=1;i<=n1;++i)printf("1 2 4\n");
		for(i=1;i<=n2;++i)printf("1 2 6\n");
		for(i=1;i<=n3;++i)printf("1 3 6\n");
	}
}