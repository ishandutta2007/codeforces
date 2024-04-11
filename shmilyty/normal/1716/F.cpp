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
const int mod=998244353;
int t,n,m,k,ans,s[2001][2001],p1[2001],p2[2001],inv[2001];
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
	m=read();
	k=read();
	p1[0]=p2[0]=1;
	for(int i=1;i<=2000;i++)
	{
		p1[i]=p1[i-1]*((m+1)/2)%mod;
		p2[i]=p2[i-1]*m%mod;
	}
	// puts("ok");
	ans=0;
	int A=1;
	for(int i=0;i<=n&&i<=k;i++)
	{
		(ans+=A*s[k][i]%mod*p1[i]%mod*qp(m,n-i)%mod)%=mod;
		(A*=(n-i))%=mod;
		// cout<<A<<endl;
	}
	cout<<ans<<'\n';
}
signed main()
{
	s[1][1]=1;
	for(int i=2;i<=2000;i++)
		for(int l=1;l<=i;l++)
			s[i][l]=(s[i-1][l-1]+s[i-1][l]*l%mod)%mod;
	t=read();
	while(t--)
		solve();
	return 0;
}