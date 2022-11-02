#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define inf 0x7f7f7f7f
using namespace std;

int n,m,i,j,k,S,T,Ans,now;
int x[1005],y[1005],z[1005];
int son[205],q[205],d[205],next[10005],ed[10005],cost[10005],flow[10005],tot,ans;
int fa[205],val[205];
bool vis[205];

void add(int u,int v,int f)
{
	next[++tot]=son[u];son[u]=tot;ed[tot]=v;flow[tot]=f;
	next[++tot]=son[v];son[v]=tot;ed[tot]=u;flow[tot]=f;
}

int find(int now,int Flow)
{
	if (now==T)	return Flow;
	int tmp,w=0,w0,i;
	for(i=son[now];i&&w<Flow;i=next[i])
	if((flow[i])&&(d[now]+1==d[ed[i]])&&(w0=min(Flow-w,flow[i]))&&(tmp=find(ed[i],w0)))
	flow[i]-=tmp,flow[i^1]+=tmp,w+=tmp;
	if(!w)d[now]=inf;
	return w;
}

int dinic(int s,int t)
{
	int t1,t2,tmp,i;
	ans=0;S=s;T=t;tot=1;
	memset(son,0,sizeof(son));
	for(i=1;i<=m;++i)add(x[i],y[i],z[i]);
	while(true)
	{
		memset(vis,true,sizeof(vis));
		q[1]=S;t1=0;t2=1;vis[S]^=1;
		while(t1<t2&&vis[T])
		for(i=son[q[++t1]];i;i=next[i])
		if(flow[i]&&vis[ed[i]])
		q[++t2]=tmp=ed[i],d[tmp]=d[q[t1]]+1,vis[tmp]^=1;
		if(vis[T])break;
		while(true)if(tmp=find(S,inf))ans+=tmp;else break;
	}
	return ans;
}

void dfs(int x)
{
	if(vis[x])return;
	vis[x]=true;
	for(int i=son[x];i;i=next[i])
	if(flow[i])dfs(ed[i]);
}

void search(int x)
{
	vis[x]=true;
	for(int i=son[x];i;i=next[i])
	if(cost[i]!=-1&&!vis[ed[i]])
	{
		if(cost[i]<cost[now]||!now)now=i;
		search(ed[i]);
	}
	vis[x]=false;
}

void work(int x)
{
	now=0;
	search(x);
	if(!now)
	{
		printf("%d ",x);
		return;
	}
	cost[now]=cost[now^1]=-1;
	int y=now;
	work(ed[y]);work(ed[y^1]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d%d",&x[i],&y[i],&z[i]);
	for(i=1;i<=n;++i)fa[i]=1;
	for(i=2;i<=n;++i)
	{
		val[i]=dinic(i,fa[i]);Ans+=val[i];
		memset(vis,false,sizeof(vis));
		dfs(i);
		for(j=i+1;j<=n;++j)if(fa[j]==fa[i]&&vis[j])fa[j]=i;
	}
	printf("%d\n",Ans);
	memset(son,0,sizeof(son));
	memset(vis,false,sizeof(vis));
	tot=1;
	for(i=2;i<=n;++i)
	{
		++tot;next[tot]=son[i];son[i]=tot;ed[tot]=fa[i];cost[tot]=val[i];
		++tot;next[tot]=son[fa[i]];son[fa[i]]=tot;ed[tot]=i;cost[tot]=val[i];
	}
	work(1);
	printf("\n");
}