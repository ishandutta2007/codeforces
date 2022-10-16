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
int t,n,sum,a[100001],ans[100001];
vector<int> G[100001];
void dfs(int x,int fa)
{
	a[x]=0-a[fa];
	for(int i:G[x])
		if(i!=fa)
			dfs(i,x);
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		G[i].clear();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		ans[i]=(int)(G[i].size());
	for(int i=1;i<=n;i++)
		cout<<ans[i]*a[i]<<" ";
	cout<<endl;
}
signed main()
{
	a[0]=-1;
	t=read();
	while(t--)
		solve();
	return 0;
}