#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
int t,n,rt,ok,dis[200001],ans[200001];
vector<int> G[200001];
void dfs(int x)
{
	if(!ok)
		return ;
	for(int i:G[x])
	{
		if(dis[i]<dis[x])
		{
			ok=0;
			return ;
		}
		ans[i]=dis[i]-dis[x];
		dfs(i);
	}
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		ans[i]=0;
		G[i].clear();
	}
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(x==i)
			rt=i;
		else
			G[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
		dis[read()]=i;
	if(dis[rt]!=1)
	{
		puts("-1");
		return ;
	}
	ok=1;
	dfs(rt);
	if(!ok)
	{
		puts("-1");
		return ;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}