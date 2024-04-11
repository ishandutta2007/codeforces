#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
typedef long long LL;
const LL INF=10000000000000000ll;
int n,m,q,fa[N];
struct edge{int v,c,n;};

struct Tree
{
	int fa[N],cnt,h[N],dep[N],siz[N],son[N],top[N];
	LL len[N];
	edge e[N<<1];

	void addedge(int u,int v,int c)
	{
		e[cnt]=(edge){v,c,h[u]},h[u]=cnt++;
		e[cnt]=(edge){u,c,h[v]},h[v]=cnt++;
	}

	void dfs(int x,int f,int d)
	{
		fa[x]=f,dep[x]=d,siz[x]=1;
		for(int i=h[x]; i!=-1; i=e[i].n)
			if(e[i].v!=f)
			{
				len[e[i].v]=len[x]+e[i].c;
				dfs(e[i].v,x,d+1),siz[x]+=siz[e[i].v];
				if(!son[x] || siz[son[x]]<siz[e[i].v])
					son[x]=e[i].v;
			}
	}

	void dfs(int x,int t)
	{
		top[x]=t;
		if(son[x]) dfs(son[x],t);
		for(int i=h[x]; i!=-1; i=e[i].n)
			if(e[i].v!=son[x] && e[i].v!=fa[x])
				dfs(e[i].v,e[i].v);
	}

	void init()
	{
		dfs(1,0,1),dfs(1,1);
	}

	int lca(int x,int y)
	{
		while(top[x]!=top[y]) dep[top[x]]>dep[top[y]]?x=fa[top[x]]:y=fa[top[y]];
		return dep[x]<dep[y]?x:y;
	}

	LL dis(int x,int y)
	{
		return len[x]+len[y]-2*len[lca(x,y)];
	}
} t;

struct Graph
{
	struct data
	{
		int x;
		LL dis;
		
		bool operator < (const data &t) const
		{
			return dis>t.dis;
		}
	} dat[N<<1];	

	bool vis[N];
	int p[50],h[N],tot,cnt;
	edge e[N<<1];
	LL dis[50][N];

	void addedge(int u,int v,int c)
	{
		e[cnt]=(edge){v,c,h[u]},h[u]=cnt++;
		e[cnt]=(edge){u,c,h[v]},h[v]=cnt++;
	}

	void ins(int x,int y)
	{
		p[++*p]=x,p[++*p]=y;
	}

	void dij(int id)
	{
		rep(i,1,n) dis[id][i]=INF,vis[i]=0;
		dat[tot=1]=(data){p[id],dis[id][p[id]]=0};
		while(tot)
		{
			int x=dat[1].x;
			pop_heap(dat+1,dat+1+tot),--tot;
			if(vis[x]) continue;
			vis[x]=1;
			for(int i=h[x]; i!=-1; i=e[i].n)
				if(dis[id][x]+e[i].c<dis[id][e[i].v])
				{
					dat[++tot]=(data){e[i].v,dis[id][e[i].v]=dis[id][x]+e[i].c};
					push_heap(dat+1,dat+1+tot);
				}
		}
	}

	void init()
	{
		rep(i,1,*p) dij(i);
	}

	LL query(int x,int y)
	{
		LL rt=INF;
		rep(i,1,*p) rt=min(rt,dis[i][x]+dis[i][y]);
		return rt;
	}
} g;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int getfa(int x)
{
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,n) fa[i]=i;
	memset(t.h,-1,sizeof(t.h));
	memset(g.h,-1,sizeof(g.h));
	rep(i,1,m)
	{
		int u=getint(),v=getint(),c=getint();
		int x=getfa(u),y=getfa(v);
		g.addedge(u,v,c);
		if(x==y) g.ins(u,v);
		else t.addedge(u,v,c),fa[x]=y;
	}
	t.init();
	g.init();
	q=getint();
	while(q--)
	{
		int x=getint(),y=getint();
		printf("%lld\n",min(t.dis(x,y),g.query(x,y)));
	}
	return 0;
}