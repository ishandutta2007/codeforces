#include <cstdio>
using namespace std;
const int maxn=200005;
int n,m,th;
int u[maxn];
int i,x,y;
int ans;
int h[maxn],to[maxn],nx[maxn],et;
int idx,dfn[maxn],low[maxn];
int st[maxn],sttop;
bool ins[maxn];
bool vis[maxn];
int bcnt,bel[maxn],sz[maxn],odeg[maxn];
void addedge(int u,int v)
{
	et++;
	to[et]=v;
	nx[et]=h[u];
	h[u]=et;
}
void dfs(int u)
{
	idx++;
	dfn[u]=low[u]=idx;
	st[++sttop]=u;
	ins[u]=1;
	vis[u]=1;
	for (int i=h[u];i;i=nx[i])
		if (!ins[to[i]])
		{
			if (!vis[to[i]])
			{
				dfs(to[i]);
				if (low[to[i]]<low[u])
					low[u]=low[to[i]];
			}
		}
		else
			if (dfn[to[i]]<low[u])
				low[u]=dfn[to[i]];
	if (low[u]==dfn[u])
	{
		bcnt++;
		sz[bcnt]=1;
		while (st[sttop]!=u)
		{
			bel[st[sttop]]=bcnt;
			ins[st[sttop]]=0;
			sttop--;
			sz[bcnt]++;
		}
		bel[u]=bcnt;
		ins[u]=0;
		sttop--;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&th);
	for (i=1;i<=n;i++)
		scanf("%d",&u[i]);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if (u[x]==u[y]-1||(u[x]==th-1&&u[y]==0))
			addedge(x,y);
		if (u[x]-1==u[y]||(u[x]==0&&u[y]==th-1))
			addedge(y,x);
	}
	for (i=1;i<=n;i++)
		if (!vis[i])
			dfs(i);
	for (i=1;i<=n;i++)
		for (x=h[i];x;x=nx[x])
			if (bel[i]!=bel[to[x]])
				odeg[bel[i]]++;
	ans=n;
	x=1;
	for (i=1;i<=bcnt;i++)
		if (odeg[i]==0&&sz[i]<ans)
		{
			x=i;
			ans=sz[i];
		}
	printf("%d\n",ans);
	for (i=1;i<=n;i++)
		if (bel[i]==x)
			printf("%d ",i);
	return 0;
}