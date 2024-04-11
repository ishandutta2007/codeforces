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
int n,m,vi[N],sum[N],fa[N][21],de[N];
vector <int> e[N];
struct node
{
	int u,v;
}sh[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct dsu//+
{
	int fa[N],sz[N];
	void init(int n)
	{
		for (int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	}
	int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
	bool merge(int a,int b)
	{
		a=find(a);b=find(b);
		if (a==b) return 0;
		if (sz[a]>sz[b]) swap(a,b);
		fa[a]=b;sz[b]+=sz[a];return 1;
	}
}T;
void dfs(int x,int father)
{
	fa[x][0]=father;
	for (int u:e[x]) if (u!=fa[x][0])
	{
		de[u]=de[x]+1;
		dfs(u,x);
	}
}
int lca(int a,int b)
{
	if (de[b]<de[a]) swap(a,b);
	for (int j=20;j>=0;j--) if (de[fa[b][j]]>=de[a]) b=fa[b][j];
	if (a==b) return a;
	for (int j=20;j>=0;j--) if (fa[a][j]!=fa[b][j]) a=fa[a][j],b=fa[b][j];
	return fa[a][0]; 
}
void dfs1(int x)
{
	for (int u:e[x]) if (u!=fa[x][0])
	{
		sum[u]+=sum[x];
		dfs1(u);
	}
}
signed main()
{
	n=read();m=read();
	T.init(n);
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		sh[i]=(node){u,v};
		if (T.merge(u,v))
		{
			e[u].push_back(v);
			e[v].push_back(u);
			vi[i]=1;
		}
	}
	dfs(1,1);
	for (int j=1;j<=20;j++) for (int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	int d=0;
	for (int i=1;i<=m;i++) if (!vi[i])
	{
		int u=sh[i].u,v=sh[i].v,LCA=lca(u,v);
		if (de[u]>de[v]) swap(u,v);
		if (u==LCA)
		{
			int x=v;
			for (int j=20;j>=0;j--) if (de[fa[x][j]]>de[LCA]) x=fa[x][j];
			d++;sum[v]++;sum[x]--;
		}
		else
		{
			sum[u]++;sum[v]++;
		}
	}
	dfs1(1);
	for (int i=1;i<=n;i++) printf("%d",(sum[i]==m-n+1-d));
	printf("\n");
}