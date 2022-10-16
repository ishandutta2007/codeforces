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
int t,n,a[200001],fac[200001],inv[200001];
const int mod=998244353;
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	if(a[n]-a[n-1]>=2)
	{
		puts("0");
		return ;
	}
	if(a[n]==a[n-1])
	{
		cout<<fac[n]<<endl;
		return ;
	}
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++)
		if(a[i]==a[n]-1)
			cnt++;
	for(int i=1;i<n;i++)
	{
		int res=fac[n-1];
		if(cnt<i)
			(res+=mod-fac[n-cnt-1]*fac[i-1]%mod*inv[i-1-cnt]%mod)%=mod;
		(ans+=res)%=mod; 
	}
	cout<<ans<<endl;
}
signed main()
{
	fac[0]=1;
	for(int i=1;i<=2e5;i++)
		fac[i]=fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=2e5;i++)
		inv[i]=mod-(mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=2e5;i++)
		(inv[i]*=inv[i-1])%=mod;
	t=read();
	while(t--)
		solve();
	return 0;
}