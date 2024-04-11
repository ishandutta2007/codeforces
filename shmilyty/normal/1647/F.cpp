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
int n,id,ans,a[500002],f[500001],g[500002],dp[2][500001];
void solve()
{
	fill(f+1,f+1+n,INF);
	fill(g+1,g+1+n,INF);
	fill(dp[0]+1,dp[0]+1+n,INF);
	fill(dp[1]+1,dp[1]+1+n,-INF);
	f[1]=0;
	for(int i=2;i<=id;i++)
	{
		if(a[i]>a[i-1])
			f[i]=min(f[i],f[i-1]);
		if(a[i]>f[i-1])
			f[i]=min(f[i],a[i-1]);
	}
	g[n]=0;
	for(int i=n;i>=id;i--)
	{
		if(a[i]>a[i+1])
			g[i]=min(g[i],g[i+1]);
		if(a[i]>g[i+1])
			g[i]=min(g[i],a[i+1]);
	}
	dp[0][id]=f[id];
	for(int i=id+1;i<=n;i++)
	{
		if(a[i]<a[i-1])
			dp[0][i]=min(dp[0][i],dp[0][i-1]);
		else
			dp[1][i]=max(dp[1][i],dp[1][i-1]);
		if(a[i]<dp[1][i-1])
			dp[0][i]=min(dp[0][i],a[i-1]);
		if(a[i]>dp[0][i-1])
			dp[1][i]=max(dp[1][i],a[i-1]);
		if(dp[1][i]>g[i])
			ans++; 
	}
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		if(a[i]>a[id])
			id=i;
	solve();
	reverse(a+1,a+1+n);
	id=n+1-id;
	solve();
	cout<<ans;
	return 0;
}