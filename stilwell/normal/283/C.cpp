#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,q,m,i,j,k,u,v,l;
int a[305],f[100005];
int lim[305],b[305][305];
bool st[305],fail;

void dfs(int i)
{
	if(st[i])
	{
		fail=true;
		return;
	}
	st[i]=true;
	int tmp=1;
	for(int j=1;j<=n;++j)
	if(b[i][j])
	{
		if(!lim[j])dfs(j);
		if(fail)return;
		if(lim[j]+1>tmp)tmp=lim[j]+1;
	}
	lim[i]=tmp;
}

int main()
{
	scanf("%d%d%d",&n,&q,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=q;++i)
	{
		scanf("%d%d",&u,&v);
		b[u][v]=1;
	}
	for(i=1;i<=n;++i)if(!lim[i])dfs(i);
	if(fail)
	{
		printf("0\n");
		return 0;
	}
	k=0;
	for(i=1;i<=n;++i)
	{
		m-=(lim[i]-1)*a[i];
		if(m<0)
		{
			printf("0\n");
			return 0;
		}
	}
	for(i=1;i<=n;++i)
	if(lim[i]>k)k=lim[i];
	for(i=k;i;--i)
	for(j=1;j<=n;++j)
	if(lim[j]==i)
	for(l=1;l<=n;++l)
	if(b[j][l])a[l]+=a[j];
	f[0]=1;
	for(i=1;i<=n;++i)
	for(j=0;j<=m;++j)
	if(j+a[i]<=m)f[j+a[i]]=(f[j+a[i]]+f[j])%1000000007;
	else break;
	printf("%d\n",f[m]);
}