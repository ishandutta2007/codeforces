#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1000005;
const int maxe=2000005;
struct Stack
{
	int st[maxe],sttop;
	void push(int u){st[++sttop]=u;}
	bool empty(){return sttop==0;}
	int top(){return st[sttop];}
	int pop(){return sttop>0?st[sttop--]:0;}
};
struct MonoQueue
{
	int q[maxn],p[maxn],ql,qr;
	void init(){ql=1;qr=0;}
	void push(int u,int pos)
	{
		while (u>q[qr]&&ql<=qr)
			qr--;
		q[++qr]=u;
		p[qr]=pos;
	}
	int top(){return q[ql];}
	int pos(){return p[ql];}
	void valid(int pos)
	{
		while (ql<=qr&&p[ql]<pos)
			ql++;
	}
	bool empty(){return qr<ql;}
};
struct Circ_Sqr_Tree
{
	int h[maxn],to[maxe],nx[maxe],et;
	int nt;
	bool sqr[maxn];
	int deg[maxn];
	Circ_Sqr_Tree(){et=1;}
	void addedge(int u,int v)
	{
		et++;
		to[et]=v;
		nx[et]=h[u];
		h[u]=et;
		et++;
		to[et]=u;
		nx[et]=h[v];
		h[v]=et;
		deg[u]++;
		deg[v]++;
	}
	int f[maxn],g[maxn];
	int st[maxn*2];
	int sec[maxn],updfrom[maxn];
	MonoQueue Q;
	bool setsqr(int u){sqr[u]=1;}
	int dist(int x,int y,int len){return min(x-y,y-x+len);}
	void cycle(int u,int from)
	{
		int len=deg[u],idx=0;
		for (int i=h[u];i;i=nx[i])
		{
			idx++;
			if (to[i]!=from)
				if (f[to[i]]+dist(len,idx,len)>f[u])
					f[u]=f[to[i]]+dist(len,idx,len);
		}
		f[u]--;
	}
	void dfs(int u,int from)
	{
		for (int i=h[u];i;i=nx[i])
			if (to[i]!=from)
			{
				dfs(to[i],u);
				if (!sqr[u])
					if (f[to[i]]+1>f[u])
					{
						sec[u]=f[u];
						f[u]=f[to[i]]+1;
						updfrom[u]=to[i];
					}
					else
						if (f[to[i]]+1>sec[u])
							sec[u]=f[to[i]]+1;
			}
		if (sqr[u])
			cycle(u,from);
	}
	void cycle2(int u,int from)
	{
		g[u]--;
		int len=deg[u],idx=0;
		Q.init();
		for (int i=h[u];i;i=nx[i])
		{
			idx++;
			st[idx]=to[i];
			Q.valid(idx-len/2);
			if (to[i]!=from&&!Q.empty())
				if (Q.top()+idx>g[to[i]])
					g[to[i]]=Q.top()+idx;
			if (to[i]!=from)
				Q.push(f[to[i]]-idx,idx);
			else
				Q.push(g[u]-idx,idx);
		}
		for (int i=h[u];i;i=nx[i])
		{
			idx++;
			st[idx]=to[i];
			Q.valid(idx-len/2);
			if (to[i]!=from&&!Q.empty())
				if (Q.top()+idx>g[to[i]])
					g[to[i]]=Q.top()+idx;
			if (to[i]!=from)
				Q.push(f[to[i]]-idx,idx);
			else
				Q.push(g[u]-idx,idx);
		}
		Q.init();
		for (int i=idx;i;i--)
		{
			Q.valid(-i-len/2);
			if (st[i]!=from&&!Q.empty())
				if (Q.top()-i>g[st[i]])
					g[st[i]]=Q.top()-i;
			if (st[i]!=from)
				Q.push(f[st[i]]+i,-i);
			else
				Q.push(g[u]+i,-i);
		}
	}
	void dfs2(int u,int from)
	{
		if (sqr[u])
			cycle2(u,from);
		for (int i=h[u];i;i=nx[i])
			if (to[i]!=from)
			{
				if (!sqr[u])
				{
					if (g[u]+1>g[to[i]])
						g[to[i]]=g[u]+1;
					if (to[i]!=updfrom[u])
					{
						if (f[u]+1>g[to[i]])
							g[to[i]]=f[u]+1;
					}
					else
						if (sec[u]+1>g[to[i]])
							g[to[i]]=sec[u]+1;
				}
				dfs2(to[i],u);
			}
		if (f[u]>g[u])
			g[u]=f[u];
	}
};
struct Cactus
{
	int h[maxn],to[maxe],nx[maxe],et;
	int nt;
	Cactus(){et=1;}
	void addedge(int u,int v)
	{
		et++;
		to[et]=v;
		nx[et]=h[u];
		h[u]=et;
		et++;
		to[et]=u;
		nx[et]=h[v];
		h[v]=et;
	}
	void input(int n,int m)
	{
		nt=n;
		int u,v;
		while (m--)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}
	}
	int dfn[maxn],low[maxn],idx;
	bool vis[maxn];
	Stack E;
	void tarjan(int u,int from,Circ_Sqr_Tree &G)
	{
		dfn[u]=low[u]=++idx;
		vis[u]=1;
		for (int i=h[u];i;i=nx[i])
			if (i!=from&&i!=(from^1))
				if (!vis[to[i]])
				{
					E.push(i);
					tarjan(to[i],i,G);
					if (low[to[i]]>dfn[u])
					{
						G.addedge(u,to[i]);
						E.pop();
					}
					if (low[to[i]]==dfn[u])
					{
						nt++;
						G.setsqr(nt);
						while (E.top()!=i&&!E.empty())
							G.addedge(nt,to[E.pop()]);
						G.addedge(nt,to[E.pop()]);
					}
					if (low[to[i]]<low[u])
						low[u]=low[to[i]];
				}
				else
					if (dfn[to[i]]<low[u])
					{
						low[u]=dfn[to[i]];
						E.push(i);
					}
	}
};
Cactus C;
Circ_Sqr_Tree G;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	C.input(n,m);
	C.tarjan(1,0,G);
	G.dfs(1,0);
	G.dfs2(1,0);
	for (int i=1;i<=n;i++)
		printf(i<n?"%d ":"%d\n",G.g[i]);
	return 0;
}