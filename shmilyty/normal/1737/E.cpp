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
const int mod=1e9+7,inv=(mod+1)/2;
int T,n,ans[1000001],f[1000001];
int qp(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)
			(res*=x)%=mod;
		(x*=x)%=mod;
		y>>=1;
	}
	return res;
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=(i+1)/2;
		if(i==n||i==1)
			x--;
		ans[i]=qp(inv,x);
	}
	for(int i=n,l=n+1,tot=0;i;i--)
	{
		while(l>=i*2+1)
		{
			l--;
			(tot+=ans[l])%=mod;
		}
		(ans[i]*=(1+mod-tot))%=mod;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<'\n';
}
signed main()
{
	T=read();
	while(T--)
		solve();
	return 0;
}