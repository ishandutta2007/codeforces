#include<bits/stdc++.h>

using namespace std;

const int maxn=1000010;

int n,m,cnt,head[maxn],fa[maxn],dep[maxn],f[maxn][21],d[maxn];

int s[maxn],tot,used,ans,g[maxn];

bool vis[maxn];

int findfa(int x) { return fa[x]==x?x:fa[x]=findfa(fa[x]); }

struct Edge
{
	int u,v,flag;
}E[maxn];

struct edge
{
	int to,nxt,id;
}e[maxn<<1];

inline void addedge(int x,int y,int id)
{
	e[++cnt].to=y;
	e[cnt].nxt=head[x];
	head[x]=cnt;
	e[cnt].id=id;
}

inline void add(int x,int y,int id) { addedge(x,y,id); addedge(y,x,id); }

void build(int x)
{
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		int y=e[i].to;
		if(f[x][0]!=y)
		{
			f[y][0]=x;
			dep[y]=dep[x]+1;
			d[y]=i;
			build(y);
		}
	}
}

inline void init()
{
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
}

inline void pushup(int &x,int d)
{
	for(int j=20;j>=0;j--)
		if(dep[x]-d>=(1<<j))
			x=f[x][j];
}

inline int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	if(dep[x]^dep[y]) pushup(x,dep[y]);
	if(x==y) return x;
	for(int j=20;j>=0;j--)
		if(f[x][j]!=f[y][j])
			x=f[x][j],y=f[y][j];
	return f[x][0];
}

void dfs(int x)
{
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
		if(f[x][0]!=e[i].to)
			dfs(e[i].to),s[x]+=s[e[i].to];
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&E[i].u,&E[i].v);
		if(findfa(E[i].u)==findfa(E[i].v)) E[i].flag=1;
		else E[i].flag=0,fa[findfa(E[i].u)]=findfa(E[i].v),add(E[i].u,E[i].v,i);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) build(i);
	init();
	for(int i=1;i<=m;i++)
		if(E[i].flag)
		{
			int LCA=lca(E[i].u,E[i].v);
			int f=-1;
			if(!((dep[E[i].u]+dep[E[i].v])&1)) f=1,tot++,used=i;
			s[E[i].u]+=f,s[E[i].v]+=f;
			s[LCA]-=f*2;
		}
	if(!tot)
	{
		printf("%d\n",m);
		for(int i=1;i<m;i++) printf("%d ",i); if(m) printf("%d",m);
		return 0;
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
	for(int i=1;i<=n;i++) if(s[i]==tot) g[++ans]=e[d[i]].id;
	if(tot==1) g[++ans]=used;
	sort(g+1,g+ans+1);
	printf("%d\n",ans);
	for(int i=1;i<ans;i++) printf("%d ",g[i]); if(ans) printf("%d",g[ans]);
}