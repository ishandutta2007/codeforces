#include<bits/stdc++.h> 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define rep_(i,a,b) for(int i=(a);i<(b).size();++i)
#define F(a) rep(a,1,n)
#define M(a,b) memset(a,b,sizeof a)
#define DC int T;cin>>T;while(T--)
#define ll long long
#define Z(a,b) sort(a+1,a+b+1)
using namespace std;
const unsigned mod=998244353;
const unsigned _mod=1e9+7;
const ll infi=0x3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(ll &x){x=0;int f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y>0){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
ll n,x[200010],y[200010],s[200010],f[200010],sum[200010];
int main()
{
	cin>>n;
	F(i) rd(x[i]),rd(y[i]),rd(s[i]);
	f[0]=2*x[1]-y[1]+mod+mod;
	sum[0]=2*x[1]-y[1]+mod+mod;
	f[0]%=mod;sum[0]%=mod; 
	rep(i,1,n-1)
	{
		f[i]=2*(x[i+1]-x[i]+mod+mod);
		f[i]%=mod;
		int p=lower_bound(x+1,x+n+1,y[i+1])-x-1;
		(f[i]+=sum[i-1]-sum[p-1]-(y[i+1]-x[p])+mod+mod+mod+mod+mod)%=mod;
		sum[i]=(sum[i-1]+f[i])%mod;
	}
	ll ans=1;
	F(i) (ans+=s[i]?f[i-1]:x[i]-x[i-1]+mod+mod)%=mod;
	cout<<ans<<'\n';
	return 0;
}