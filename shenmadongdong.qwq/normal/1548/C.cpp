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
const ll infi=0x3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
void rd(auto &x){x=0;int f=1;char ch=getchar();while(ch<48||ch>57){if(ch==45)f=-1;ch=getchar();}while(ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();x*=f;}
ll ksm(ll x,ll y=mod-2,ll m=mod){ll ret=1;while(y){if(y&1)ret=ret*x%m;y>>=1ll;x=x*x%m;}return ret;}
ll qpow(ll x,ll y=2){ll ret=1;while(y>0){if(y&1ll)ret=ret*x;y>>=1ll;x=x*x;}return ret;}
/*
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
*/
ll n,q,s[3000010][3],fac[3000010],inv[3000010],inc[3000010];
int main() 
{
    *fac=*inc=inc[1]=1;
    rep(i,1,3000005) fac[i]=fac[i-1]*i%mod;
    inv[3000005]=ksm(fac[3000005]);
    req(i,3000005,1) inv[i-1]=inv[i]*i%mod;
    rep(i,2,3000005) inc[i]=(mod-mod/i)*inc[mod%i]%mod;
    cin>>n;
    rep(_,0,2) s[1][_]=(3*n-1+_*2)*n%mod*(mod+1>>1)%mod;
    rep(i,2,3*n)
    {
        ll x=s[i-1][0]*i%mod,y=s[i-1][1]*i%mod;
        ll sum=inv[3*n-i]*fac[3*n+1]%mod*inc[i+1]%mod;
        s[i][0]=inc[3]*(sum-(2*x+y)%mod+mod)%mod;
        s[i][1]=(s[i][0]+x)%mod;
        s[i][2]=(s[i][1]+y)%mod;
    }
    DC
    {
        int x;
        rd(x);
        cout<<inv[x]*s[x][2]%mod<<'\n';
    }
    return 0;
}