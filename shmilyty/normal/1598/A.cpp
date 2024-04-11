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
int t,n,ans,vis[2][101];
void dfs(int x,int y)
{
	if(x==1&&y==n-1)
	{
		ans=1;
		return ;
	}
	vis[x][y]=1;
	if(x==0&&!vis[x+1][y])
	{
		dfs(x+1,y);
		if(ans)
			return ;
	}
	if(y!=n-1&&!vis[x][y+1])
	{
		dfs(x,y+1);
		if(ans)
			return ;
	}
	if(y!=n-1&&!vis[x^1][y+1])
	{
		dfs(x^1,y+1);
		if(ans)
			return ;
	}
}
void solve()
{
	n=read();
	ans=0;
	for(int i=0;i<=1;i++)
	{
		string s;
		cin>>s;
		for(int l=0;l<n;l++)
			vis[i][l]=s[l]-'0';
	}
	dfs(0,0);
	if(ans)
		puts("Yes");
	else
		puts("No");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}