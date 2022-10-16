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
const int N=500001;
int n,ans,g[N<<1],f[N],sz[N];
std::vector<array<int,2>> G[N];
std::vector<int> v[N];
void dfs(int x,int fa)
{
	sz[x]=1;
	for(auto i:G[x])
		if(i[0]!=fa)
		{
			f[i[0]]=v[i[1]].back();
			v[i[1]].push_back(i[0]);
			dfs(i[0],x);
			sz[x]+=sz[i[0]];
			g[i[0]]+=sz[i[0]];
			g[f[i[0]]]-=sz[i[0]];
			v[i[1]].pop_back();
		}
}
signed main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read(),z=read();
		G[x].push_back({y,z});
		G[y].push_back({x,z});
	}
	for(int i=1;i<=n;i++)
	{
		v[i].push_back(i+n);
		g[n+i]=n;
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		ans+=g[i]*g[f[i]];
	cout<<ans;
	return 0;
}