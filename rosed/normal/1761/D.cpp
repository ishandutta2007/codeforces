// LUOGU_RID: 96157102
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
const int mod=1e9+7;
void solve()
{
	auto fast=[&](int x,int k) -> int
	{
		int ret=1;
		while(k)
		{
			if(k&1) ret=ret*x%mod;
			x=x*x%mod;
			k>>=1;
		}
		return ret;
	};
	int n,k;
	cin>>n>>k;
	if(k==0)
	{
		cout<<fast(3,n)<<'\n';
		return;
	}
	vector<int> fac(n+1),inv(n+1);
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
	inv[n]=fast(fac[n],mod-2);
	for(int i=n-1;i>=1;--i) inv[i]=inv[i+1]*(i+1)%mod;
	auto C=[&](int n,int m) -> int
	{
		if(n<m||m<0) return 0;
		return fac[n]*inv[m]%mod*inv[n-m]%mod;
	};
	int ans=0;
	for(int i=0;i<=n;++i)
	{
		ans+=fast(3,n-i)*C(n+1-k-1,(i+1)-(i+1)/2-1)%mod*C(k-1,(i+1)/2-1)%mod;
		ans%=mod;
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; //cin>>T;
	while(T--) solve();
	return 0;
}