#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,ans;
int fa[2000005];

int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=2000000;++i)fa[i]=i-1;
	for(;n;--n)
	{
		scanf("%d",&k);
		fa[k]=k;
	}
	ans=1;
	for(i=2;i<=1000000;++i)
	{
		for(j=i;j<=2000000;j+=i)
		{
			k=get(j-1);
			if(j==i&&k)break;
			if(k-(j-i)>m)break;
		}
		if(j>2000000)ans=i;
	}
	printf("%d\n",ans);
}