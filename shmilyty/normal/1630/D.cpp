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
int t,n,m,ans,a[1000001];
array<int,2>f,g;
int solve(int x)
{
	int res=0;
	for(int i=0;i<x;i++)
	{
		f={0,-INF};
		for(int l=i;l<n;l+=x)
		{
			g[0]=max(f[0]+a[l],f[1]-a[l]);
			g[1]=max(f[0]-a[l],f[1]+a[l]);
			f=g;
		}
		res+=f[0];
	}
	return res;
}
void solve()
{
	n=read();
	m=read();
	for(int i=0;i<n;i++)
		a[i]=read();
	int g=0;
	while(m--)
		g=__gcd(g,read());
	if(g==1)
	{
		int ans=0;
		for(int i=0;i<n;i++)
			ans+=abs(a[i]);
		cout<<ans<<'\n';
		return ;
	}
	ans=solve(g);
	for(int i=0;i<g;i++)
		a[i]=-a[i];
	cout<<max(ans,solve(g))<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}