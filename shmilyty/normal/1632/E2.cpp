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
int t,n,f[300001],g[300001],dep[300001];
vector<int> G[300001];
void dfs(int x,int fa)
{
	g[x]=dep[x];
	for(int i:G[x])
		if(i!=fa)
		{
			dep[i]=dep[x]+1;
			dfs(i,x);
			if(g[x])
				f[min(g[x],g[i])-1]=max(f[min(g[x],g[i])-1],g[x]+g[i]-2*dep[x]+1);
			g[x]=max(g[x],g[i]);
		}
	if(dep[x])
		f[dep[x]-1]=max(f[dep[x]-1],1ll);
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		G[i].clear();
		f[i]=0;
	}
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	for(int i=n-2;~i;i--)
		f[i]=max(f[i],f[i+1]);
	int mx=0,ans=0;
	for(int i=1;i<=n;i++)
		mx=max(mx,dep[i]);
	for(int i=1;i<=n;i++)
	{
		while(ans<mx&&f[ans]/2+i>ans)
			ans++;
		cout<<ans<<" ";
	}
	cout<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}