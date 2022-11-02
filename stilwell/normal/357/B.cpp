#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,x,y,z;
int f[100005];

int main()
{
	scanf("%d%d",&n,&m);
	for(;m;--m)
	{
		scanf("%d%d%d",&x,&y,&z);
		k=7;k-=f[x];k-=f[y];k-=f[z];
		if(!f[x])f[x]=k&-k,k-=k&-k;
		if(!f[y])f[y]=k&-k,k-=k&-k;
		if(!f[z])f[z]=k&-k,k-=k&-k;
	}
	for(i=1;i<=n;++i)
	{
		if(f[i]==1)printf("1");
		else if(f[i]==2)printf("2");
		else printf("3");
		if(i==n)printf("\n");
		else printf(" ");
	}
}