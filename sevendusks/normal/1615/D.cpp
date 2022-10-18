 /*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int TT,n,m,s[N],de[N],col[N];
vector <pair<int,int> > e[N];
vector <int> E[N];
struct node
{
	int u,v,w;
}sh[N];
node q[N];
struct dsu//+
{
	int fa[N],sz[N];
	void init(int n)
	{
		for (int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	}
	int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
	void merge(int a,int b)
	{
		a=find(a);b=find(b);
		if (a==b) return;
		if (sz[a]>sz[b]) swap(a,b);
		fa[a]=b;sz[b]+=sz[a];
	}
}T;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void dfs(int x,int fa)
{
	for (auto [u,w]:e[x]) if (u!=fa)
	{
		s[u]=s[x];
		if (w!=-1) s[u]^=w;
		dfs(u,x);
	}
}
bool bl;
void dfs1(int x)
{
	for (int u:E[x])
	{
		if (col[u]!=-1)
		{
			if (col[u]==col[x]) bl=0;
			continue;
		}
		col[u]=col[x]^1;
		dfs1(u);
	}
}
signed main()
{
	TT=read();
	while (TT--)
	{
		n=read();m=read();
		T.init(n);
		for (int i=1;i<=n;i++) e[i].clear();
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read(),w=read();
			sh[i]=(node){u,v,w};
			e[u].emplace_back(v,w);e[v].emplace_back(u,w);
			if (sh[i].w!=-1) T.merge(u,v);
		}
		s[1]=0;
		dfs(1,1);
		int cnt=0;
		for (int i=1;i<=m;i++)
		{
			int u=read(),v=read(),w=read();
			int now=s[u]^s[v];
			if (__builtin_popcountll(now)%2==w) T.merge(u,v);
			else q[++cnt]=(node){u,v,w}; 
		}
		for (int i=1;i<=n;i++) E[i].clear();
		for (int i=1;i<=cnt;i++)
		{
			int u=T.find(q[i].u),v=T.find(q[i].v);
			E[u].push_back(v);E[v].push_back(u);
		}
		for (int i=1;i<=n;i++) col[i]=-1;
		bl=1;
		for (int i=1;i<=n;i++) if (col[i]==-1) col[i]=0,dfs1(i);
		if (!bl)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i=1;i<n;i++)
		{
			int u=sh[i].u,v=sh[i].v;
			if (sh[i].w==-1) sh[i].w=(col[T.find(u)]!=col[T.find(v)]);
			printf("%d %d %d\n",u,v,sh[i].w);
		}
	}
}