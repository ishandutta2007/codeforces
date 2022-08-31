#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fxaa
#define y0 fxbb
#define x1 fxcc
#define y1 fxdd
#define st first
#define nd second
using namespace std;
using ll=long long;
using ld=long double;
constexpr int N=1e6+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
int a,b,n,k;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main(){
    scanf("%d%d%d%d",&n,&k,&a,&b);
    int s1=a+1,s2=k+1-a,t1=b+1,t2=k+1-b;
    ll ans0=1ll*mod*mod,ans1=0;
    rep(i,n){
        if(s1-1<=k+1-s1){
            if(t1-1<=k+1-t1){
                ll tmp=(t1-s1+1ll*k*n+1ll*i*k)%(1ll*k*n);
                ll upd=1ll*k*n/gcd(1ll*k*n,tmp);
                ans0=min(ans0,upd);
                ans1=max(ans1,upd);
            }
            if(t2-1>=k+1-t2){
                ll tmp=(t2-s1+1ll*k*n+1ll*i*k)%(1ll*k*n);
                ll upd=1ll*k*n/gcd(1ll*k*n,tmp);
                ans0=min(ans0,upd);
                ans1=max(ans1,upd);
            }
        }
        if(s2-1>=k+1-s2){
            if(t1-1<=k+1-t1){
                ll tmp=(t1-s2+1ll*k*n+1ll*i*k)%(1ll*k*n);
                ll upd=1ll*k*n/gcd(1ll*k*n,tmp);
                ans0=min(ans0,upd);
                ans1=max(ans1,upd);
            }
            if(t2-1>=k+1-t2){
                ll tmp=(t2-s2+1ll*k*n+1ll*i*k)%(1ll*k*n);
                ll upd=1ll*k*n/gcd(1ll*k*n,tmp);
                ans0=min(ans0,upd);
                ans1=max(ans1,upd);
            }
        }
    }
    printf("%lld %lld\n",ans0,ans1);
    return 0;
}