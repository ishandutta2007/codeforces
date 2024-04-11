#include <bits/stdc++.h>
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
ll n,a[1010],s[1010],p[1010],ans;
int main()
{
	cin>>n;
	F(i) rd(a[i]);
	F(i) s[i]=s[i-1]+a[i]*(i&1?1:-1),p[i]=a[i]*(i&1?1:-1);
	rep(i,1,n+1>>1)
	{
		ll mn=infi,ts=0;
		rep(j,i<<1,n)
		{
			ll rp=s[2*i-1]-s[j-1];
			if (max(1ll,-mn)<=a[2*i-1]&&(j&1^1)&&max(1ll,-mn)<=min(a[j]+rp,a[2*i-1])) ans+=min(a[j]+rp,a[2*i-1])-max(1ll,-mn),ans++;
			ts+=p[j],mn=min(mn,ts);
		}
	}
	cout<<ans<<'\n';
	return 0;
}