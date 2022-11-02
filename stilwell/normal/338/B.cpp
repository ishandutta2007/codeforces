#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,d,i,j,k,ans,u,v,tot;
int son[100005],next[200005],ed[200005];
int Max[100005],Max_[100005];
bool p[100005],vis[100005];

void dfs(int x)
{
	vis[x]=true;
	Max[x]=Max_[x]=-100000;
	if(p[x])Max[x]=0;
	for(int i=son[x];i;i=next[i])
	if(!vis[ed[i]])
	{
		dfs(ed[i]);
		if(Max[ed[i]]+1>Max[x])Max_[x]=Max[x],Max[x]=Max[ed[i]]+1;
		else if(Max[ed[i]]+1>Max_[x])Max_[x]=Max[ed[i]]+1;
	}
}

void find(int x,int y)
{
	vis[x]=false;
	if(Max[x]<=d&&y<=d)++ans;
	for(int i=son[x];i;i=next[i])
	if(vis[ed[i]])
	{
		if(Max[ed[i]]+1==Max[x])find(ed[i],max(Max_[x],y)+1);
		else find(ed[i],max(Max[x],y)+1);
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for(i=1;i<=m;++i)
	{
		scanf("%d",&u);
		p[u]=true;
	}
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		++tot;next[tot]=son[u];son[u]=tot;ed[tot]=v;
		++tot;next[tot]=son[v];son[v]=tot;ed[tot]=u;
	}
	dfs(1);
	find(1,-100000);
	printf("%d\n",ans);
}