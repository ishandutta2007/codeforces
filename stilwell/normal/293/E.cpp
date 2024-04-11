#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,L,W,i,j,k,u,v,c,tot;
int son[100005],next[200005],ed[200005],cost[200005];
int sum[100005],size[100005],root,sizesum;
bool vis[100005];
long long ans;

struct node
{
	int u,v;
}t[100005];
inline bool cmp(const node &a,const node &b){return a.v<b.v;}

void dfs1(int x)
{
	size[x]=1;vis[x]=true;
	for(int i=son[x];i;i=next[i])
	if(!vis[ed[i]])
	{
		dfs1(ed[i]);
		size[x]+=size[ed[i]];
	}
	vis[x]=false;
}

void dfs2(int x)
{
	vis[x]=true;
	if(size[x]!=sizesum)size[x]=sizesum-size[x];
	for(int i=son[x];i;i=next[i])
	if(!vis[ed[i]])
	{
		if(size[ed[i]]>size[x])size[x]=size[ed[i]];
		dfs2(ed[i]);
	}
	if(size[x]<size[root]||root==0)root=x;
	vis[x]=false;
}

void dfs3(int x,int y,int z)
{
	vis[x]=true;
	++tot;t[tot].u=y;t[tot].v=z;
	for(int i=son[x];i;i=next[i])
	if(!vis[ed[i]])dfs3(ed[i],y+1,z+cost[i]);
	vis[x]=false;
}

long long work()
{
	int i,l=1,r;long long ans=0;
	sort(t+1,t+tot+1,cmp);
	for(r=tot;r>=1;--r)
	{
		for(;l<=tot&&t[l].v+t[r].v<=W;++l)
		for(i=t[l].u;i<=tot;i+=i&-i)
		++sum[i];
		for(i=min(tot,L-t[r].u);i>0;i-=i&-i)ans+=sum[i];
	}
	for(i=1;i<=tot;++i)sum[i]=0;
	tot=0;
	return ans;
}

void dfs(int x)
{
	dfs1(x);
	sizesum=size[x];root=0;
	dfs2(x);
	vis[x=root]=true;
	for(int i=son[x];i;i=next[i])
	if(!vis[ed[i]])
	{
		dfs3(ed[i],1,cost[i]);
		ans-=work();
	}
	for(int i=son[x];i;i=next[i])if(!vis[ed[i]])dfs3(ed[i],1,cost[i]);
	for(int i=1;i<=tot;++i)if(t[i].u<=L&&t[i].v<=W)ans+=2;
	ans+=work();
	for(int i=son[x];i;i=next[i])if(!vis[ed[i]])dfs(ed[i]);
}

int main()
{
	scanf("%d%d%d",&n,&L,&W);
	for(i=2;i<=n;++i)
	{
		scanf("%d%d",&v,&c);u=i;
		++tot;next[tot]=son[u];son[u]=tot;ed[tot]=v;cost[tot]=c;
		++tot;next[tot]=son[v];son[v]=tot;ed[tot]=u;cost[tot]=c;
	}
	tot=0;
	dfs(1);
	printf("%I64d\n",ans/2);
}