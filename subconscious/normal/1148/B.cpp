#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define st first
#define nd second
#define x0 fuckcjb
#define y0 fuckjsb
#define x1 fucklgl
#define y1 fucklyw
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,mod=1e9+7;
const ld eps=1e-12;
ll a[N],b[N],n,m,ta,tb,k;
int main(){
    scanf("%lld%lld%lld%lld%lld",&n,&m,&ta,&tb,&k);
    rep(i,n)scanf("%lld",a+i);
    rep(i,m)scanf("%lld",b+i);
    ll ans=0;
    for(ll i=0;i<=n&&i<=k;++i){
        ll pa=i+1;
        if(pa>n){ans=1e18;continue;}
        ll pos=lower_bound(b+1,b+m+1,a[pa]+ta)-b;
        ll del=k-i;
        if(pos+del>m){ans=1e18;continue;}
        ans=max(ans,b[pos+del]+tb);
    }
    if(ans==1e18)puts("-1");else printf("%lld\n",ans);
}