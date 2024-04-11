#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,u,v;
int son[100005],next[200005],ed[200005],tot;
int sum[100005],ans[100005],link[100005];
int FA[100005][30],deep[100005];
bool vis[100005];

void findFA(int p)
{
	int i,j;
	vis[p]=true;
	for(i=son[p];i;i=next[i])
	if(!vis[ed[i]])
	{
		link[ed[i]]=i/2;
		deep[ed[i]]=deep[p]+1;
		FA[ed[i]][1]=p;
		j=1;
		while(FA[ed[i]][j])
		{
			FA[ed[i]][j+1]=FA[FA[ed[i]][j]][j];
			++j;
		}
		findFA(ed[i]);
	}
}

int LCA(int u,int v)
{
	int i=0,j;
	if(deep[u]>deep[v])swap(u,v);
	j=deep[v]-deep[u];
	while(j)
	{
		++i;
		if(j%2)v=FA[v][i];
		j/=2;
	}
	if(u==v)return u;
	for(i=20;i>=1;--i)
	if(FA[u][i]!=FA[v][i])
	u=FA[u][i],v=FA[v][i];
	return FA[u][1];
}

void dfs(int x)
{
	vis[x]=true;
	for(int i=son[x];i;i=next[i])
	if(!vis[ed[i]])
	{
		dfs(ed[i]);
		sum[x]+=sum[ed[i]];
	}
	ans[link[x]]=sum[x];
}

int main()
{
	scanf("%d",&n);tot=1;
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		++tot;next[tot]=son[u];son[u]=tot;ed[tot]=v;
		++tot;next[tot]=son[v];son[v]=tot;ed[tot]=u;
	}
	findFA(1);
	scanf("%d",&m);
	for(;m;--m)
	{
		scanf("%d%d",&u,&v);
		++sum[u];++sum[v];
		sum[LCA(u,v)]-=2;
	}
	for(i=1;i<=n;++i)vis[i]=false;
	dfs(1);
	for(i=1;i<n;++i)
	{
		printf("%d",ans[i]);
		if(i==n-1)printf("\n");
		else printf(" ");
	}
}