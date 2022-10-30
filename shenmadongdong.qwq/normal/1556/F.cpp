#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define rep_(i,a,b) for(int i=(a);i<(b).size();++i)
#define F(a) rep(a,1,n)
#define M(a,b) memset(a,b,sizeof a)
#define DC int __;cin>>__;while(__--)
#define ll long long
#define Z(a,b) sort(a+1,a+b+1)
using namespace std;
const unsigned _mod=998244353;
const unsigned mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(auto &x){x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch==45)f=-1;ch=getchar();}while(isdigit(ch))x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y){if(y&1)ret=ret*x;y>>=1;x=x*x;}return ret;}
/*
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
	[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
const int JS=2e6+5;
ll fac[JS+10],inv[JS+10],inc[JS+10];
ll n,a[15],f[17010],v1[JS],cnt1,v2[JS],cnt2;
int main()
{
	*fac=1;
	rep(i,1,JS) fac[i]=fac[i-1]*i%mod;
	inv[JS]=ksm(fac[JS]);
	req(i,JS,1) inv[i-1]=inv[i]*i%mod;
	*inc=1;
	rep(i,1,JS) inc[i]=inv[i]*fac[i-1]%mod;
	cin>>n;
	F(i) rd(a[i]);
 	rep(_,1,qpow(2,n)-1) 
	{
		f[_]=1;
		for(int __=_-1&_;__;__=__-1&_) 
		{
			int xyfak=__^_;
			cnt1=cnt2=0;
			F(i) 
			{
				if (__>>i-1&1) v1[++cnt1]=i;
				if (xyfak>>i-1&1) v2[++cnt2]=i;
			}
			ll pq=1;
			rep(i,1,cnt1) rep(j,1,cnt2) (pq*=a[v1[i]]*inc[a[v1[i]]+a[v2[j]]]%mod)%=mod;
			(f[_]-=pq*f[__])%=mod;
			(f[_]+=mod)%=mod;
		}
	}
	ll ans=0;
	rep(_,1,qpow(2,n)-1) 
	{
		cnt1=cnt2=0;
		F(i)
		{
			if (_>>i-1&1) v1[++cnt1]=i;
			if (_>>i-1&1^1) v2[++cnt2]=i;
		}
		ll pq=1;
		rep(i,1,cnt1) rep(j,1,cnt2) (pq*=a[v1[i]]*inc[a[v1[i]]+a[v2[j]]]%mod)%=mod;
		(ans+=pq*f[_]%mod*cnt1)%=mod;
	}
	cout<<ans<<'\n';
	return 0;
}