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
int t,n,m,ans[400001],vis[400001];
vector<int> G[400001];
void dfs(int x,int s)
{
	if(s==1)
		ans[x]=-1;
	if(!vis[x]&&ans[x]>2)
		return ;
	if(vis[x]==2)
		return ;
	if(ans[x]!=-1)
		ans[x]++;
	if(vis[x]==1)
	{
		s=1;
		vis[x]=2;
	}
	else
		vis[x]=1;
	for(int i:G[x])
		dfs(i,s);
	if(vis[x]!=2)
		vis[x]--;
}
void solve()
{
	n=read();
	m=read();
	fill(ans+1,ans+1+n,0);
	fill(vis+1,vis+1+n,0);
	for(int i=1;i<=n;i++)
		G[i].clear();
	while(m--)
	{
		int x=read(),y=read();
		G[x].push_back(y);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		cout<<min(2ll,ans[i])<<" ";
	cout<<endl;
} 
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}