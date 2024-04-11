#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,u,v,opt;
int son[200005],next[400005],ed[400005],tot;
int flag[200005],st[200005],en[200005];
int a[200005];
long long ans,sum[1000005];

void dfs(int x)
{
	st[x]=++tot;
	for(int i=son[x];i;i=next[i])
	if(!flag[ed[i]])
	{
		flag[ed[i]]=-flag[x];
		dfs(ed[i]);
	}
	en[x]=++tot;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		++tot;next[tot]=son[u];son[u]=tot;ed[tot]=v;
		++tot;next[tot]=son[v];son[v]=tot;ed[tot]=u;
	}
	tot=0;flag[1]=1;
	dfs(1);
	for(;m;--m)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&u,&v);
			for(i=st[u];i<=tot;i+=i&-i)sum[i]+=flag[u]*v;
			for(i=en[u];i<=tot;i+=i&-i)sum[i]-=flag[u]*v;
		}
		else
		{
			scanf("%d",&u);
			ans=a[u];
			for(i=st[u];i>=1;i-=i&-i)ans+=flag[u]*sum[i];
			printf("%I64d\n",ans);
		}
	}
}