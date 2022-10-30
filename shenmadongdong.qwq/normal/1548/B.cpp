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
ll n,a[2000010],b[2000010],p[200010];
struct wzak{
    ll l,r,w;
}G[800010];
ll Sum(ll rt,ll L,ll R)
{
    if (G[rt].r<=R&&L<=G[rt].l) return G[rt].w;
    ll ans=0,mid=G[rt].l+G[rt].r>>1;
    if (L<=mid) ans=__gcd(Sum(rt<<1,L,R),ans);
    if (R>mid) ans=__gcd(Sum(rt<<1|1,L,R),ans);
    return ans;
}
void build(ll rt,ll L,ll R)
{
    G[rt].w=0,G[rt].r=R,G[rt].l=L;
    if (L==R) return G[rt].w=b[L],void();
    ll mid=L+R>>1;
    build(rt<<1,L,mid);
    build(rt<<1|1,mid+1,R);
    G[rt].w=__gcd(G[rt<<1].w,G[rt<<1|1].w);
}
int main() 
{
    DC
    {
        ll l=1,mx=0;
        cin>>n;
        F(i) rd(a[i]);
        if (n==1) {puts("1");continue;}
        rep(i,1,n-1) b[i]=a[i+1]-a[i];
        rep(i,1,n-1) if (b[i]<0) b[i]=-b[i];
        build(1,1,n-1);
        rep(i,1,n-1)
        {
            while(l<=i&&Sum(1,l,i)==1) l++;
            p[i]=l;
        }
        rep(i,1,n-1) mx=max(i-p[i]+2,mx);
        cout<<mx<<'\n';
    }
    return 0;
}