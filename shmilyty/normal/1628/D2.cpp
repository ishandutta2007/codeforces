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
const int mod=1e9+7;
int t,n,m,k,ans,fac[1000001],inv[1000001];
int C(int x,int y)
{
	if(x<0||y<0||x<y)
		return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int qp(int x)
{
	int bse=mod/2+1,ans=1;
	while(x)
	{
		if(x&1)
			(ans*=bse)%=mod;
		x>>=1;
		(bse*=bse)%=mod;
	}
	return ans;
} 
void solve()
{
	n=read();
	m=read();
	k=read();
	ans=0;
	for(int i=n-m;i<=n;i++)//i,i+m-n k*(n-i)
	{ 
		int x=C(max(i-1,0ll),i+m-n);
		(ans+=qp(i)*x%mod*k%mod*(n-i)%mod)%=mod;
	}
	cout<<ans<<'\n'; 
}
signed main()
{
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=1000000;i++)
		fac[i]=(fac[i-1]*i)%mod;
	for(int i=2;i<=1000000;i++)
		inv[i]=mod-mod/i*inv[mod%i]%mod;
	for(int i=2;i<=1000000;i++)
		(inv[i]*=inv[i-1])%=mod;
	t=read();
	while(t--)
		solve();
	return 0;
}