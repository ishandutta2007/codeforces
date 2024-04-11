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
int t,n,s[200001];
vector<int> G[200001];
void dfs(int x,int fa)
{
	s[x]=0;
	for(int i:G[x])
		if(i!=fa)
		{
			dfs(i,x);
			if(!s[i])
				s[x]++;
		}
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
	int ans=s[1],cnt=s[1];
	for(int i=2;i<=n;i++)
		if(s[i])
		{
			if(cnt)
				ans+=s[i]-1;
			else
			{
				cnt=1;
				ans+=s[i];
			}
		}
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}