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
const int mod=998244353;
int t,n,ans,a[500001],g[500001],f[500001];
void solve()
{
	n=read();
	ans=0;
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=0;i<=n;i++)
		g[i]=f[i]=0;
	for(int i=1;i<=n;i++)
	{
		int x=f[a[i]],low=0,up=0;
		if(a[i])
			(x+=f[a[i]-1])%=mod;
		else
			x++;
		if(a[i]>1)
			(low+=f[a[i]-2])%=mod;
		if(a[i])
			(low+=g[a[i]-1])%=mod;
		if(a[i]==1)
			(low+=1)%=mod;
		if(a[i]<n)
			up=g[a[i]+1];
		(ans+=x+up+low)%=mod;
		(f[a[i]]+=x)%=mod;
		if(a[i])
			(g[a[i]-1]+=low)%=mod;
		if(a[i]<n)
			(g[a[i]+1]+=up)%=mod; 
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