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
int t,n,d[100001],ans[100001];
vector<array<int,2>> G[100001];
void dfs(int x,int fa,int lst)
{
	for(auto i:G[x])
		if(i[0]!=fa)
		{
			ans[i[1]]=lst;
			dfs(i[0],x,7-lst);
		}
}
void solve()
{
	n=read();
	fill(d+1,d+1+n,0);
	for(int i=1;i<=n;i++)
		G[i].clear();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		d[x]++;
		d[y]++;
		G[x].push_back({y,i});
		G[y].push_back({x,i}); 
	}
	int st;
	for(int i=1;i<=n;i++)
		if(d[i]>2)
		{
			puts("-1");
			return ;
		}
		elif(d[i]==1)
			st=i;
	dfs(st,0,2);
	for(int i=1;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}