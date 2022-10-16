#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,cnt,q,m,dfn[100001],dep[100001],ok[100001],g[100001],pre[100001][20];
vector<int> v,G[100001],t[100001];
void dfs(int x,int fa)
{
	pre[x][0]=fa;
	dfn[x]=++cnt;
	dep[x]=dep[fa]+1;
	for(int i:G[x])
		if(i!=fa)
			dfs(i,x);
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=19;~i;i--)
		if(dep[x]-(1<<i)>=dep[y])
			x=pre[x][i];
	if(x==y)
		return x;
	for(int i=19;~i;i--)
		if(pre[x][i]!=pre[y][i])
		{
			x=pre[x][i];
			y=pre[y][i];
		}
	return pre[x][0];
}
bool cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}
int get(int x)
{
	int res=0,cnt=0;
	g[x]=ok[x];
	for(int i:t[x])
	{
		res+=get(i);
		cnt+=g[i];
	}
	if(ok[x])
		return res+cnt;
	if(cnt>1)
		return res+1;
	g[x]=cnt;
	return res;
}
void solve()
{
	m=read();
	v.clear();
	for(int i=1;i<=m;i++)
	{
		int x=read();
		v.push_back(x);
		ok[x]=1;
	}
	for(int i:v)
		if(ok[pre[i][0]])
		{
			puts("-1");
			for(int l:v)
				ok[l]=0;
			return ;
		}
	sort(ALL(v),cmp);
	for(int i=1;i<m;i++)
	{
		int x=lca(v[i-1],v[i]);
		if(x!=v[i-1]&&x!=v[i])
			v.push_back(x);
	}
	sort(ALL(v));
	v.resize(unique(ALL(v))-v.begin());
	sort(ALL(v),cmp);
	for(int i=1;i<v.size();i++)
		t[lca(v[i-1],v[i])].push_back(v[i]);
	cout<<get(v[0])<<'\n';
	for(int i:v)
		t[i].clear();
	for(int i:v)
		ok[i]=g[i]=0;
}
signed main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<20;i++)
		for(int l=1;l<=n;l++)
			pre[l][i]=pre[pre[l][i-1]][i-1];
	q=read();
	while(q--)
		solve();
	return 0;
}