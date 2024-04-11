#include <stdio.h>
#include <stdlib.h>
using namespace std;

int son[100005],next[200005],ed[200005],tot;
int size[100005],boss[100005][30],deep[100005][30];
int n,m,i,j,k,u,v,root,sum;
bool vis[100005];
int close[100005];

void dfs1(int x)
{
	vis[x]=true;
	size[x]=1;
	for(int i=son[x];i;i=next[i])
	if(!vis[ed[i]])
	{
		dfs1(ed[i]);
		size[x]+=size[ed[i]];
	}
	vis[x]=false;
}

void dfs2(int x,int S)
{
	int heavy=S;
	vis[x]=true;
	for(int i=son[x];i;i=next[i])
	if(!vis[ed[i]])
	{
		if(size[ed[i]]>heavy)heavy=size[ed[i]];
		dfs2(ed[i],S+size[x]-size[ed[i]]);
	}
	if(heavy<sum)root=x,sum=heavy;
	vis[x]=false;
}

void dfs3(int x,int d)
{
	if(x!=root)
	{
		++boss[x][0];
		boss[x][boss[x][0]]=root;
		deep[x][boss[x][0]]=d;
	}
	vis[x]=true;
	for(int i=son[x];i;i=next[i])
	if(!vis[ed[i]])dfs3(ed[i],d+1);
	vis[x]=false;
}

void build(int x)
{
	
	dfs1(x);
	root=x;sum=0x7fffffff;
	dfs2(x,0);
	x=root;
	dfs3(x,0);
	vis[x]=true;
	for(int i=son[x];i;i=next[i])
	if(!vis[ed[i]])build(ed[i]);
}

void Min(int &a,int b){if(b<a)a=b;}
void C(int x)
{
	close[x]=0;
	for(int i=boss[x][0];i;--i)
	Min(close[boss[x][i]],deep[x][i]);
}
int Q(int x)
{
	int ans=close[x];
	for(int i=boss[x][0];i;--i)
	Min(ans,deep[x][i]+close[boss[x][i]]);
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		++tot;next[tot]=son[u];son[u]=tot;ed[tot]=v;
		++tot;next[tot]=son[v];son[v]=tot;ed[tot]=u;
	}
	build(1);
	for(i=1;i<=n;++i)close[i]=10000000;
	C(1);
	for(;m;--m)
	{
		scanf("%d%d",&u,&v);
		if(u==1)C(v);else printf("%d\n",Q(v));
	}
}