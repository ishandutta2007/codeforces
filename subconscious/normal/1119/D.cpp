#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuckcjb
#define y0 fxxkcjb
#define x1 fckxcjb
#define y1 fasdlfj
#define ep emplace_back
using namespace std;
using ll=long long;
using ld=long double;
constexpr int N=1e6+5,mod=1e9+7;
constexpr ld inf=1e50,eps=1e-10;
struct node{
    ll x,key;
}c[N];
ll a[N],b[N],d[N];int n,q;
ll ans[N];
bool cmp(node x,node y){return x.x<y.x;}
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%lld",a+i);
    sort(a+1,a+n+1);
    rep(i,n-1)b[i]=a[i+1]-a[i];b[n]=9e18;
    sort(b+1,b+n+1);
    rep(i,n)d[i]=d[i-1]+b[i];
    scanf("%d",&q);
    rep(i,q){
        ll l,r;scanf("%lld%lld",&l,&r);
        c[i].x=r-l+1;c[i].key=i;
    }
    sort(c+1,c+q+1,cmp);
    int cur=0;
    rep(i,q){
        while(cur<n&&b[cur+1]<=c[i].x)++cur;
        ans[c[i].key]=d[cur]+(n-cur)*c[i].x;
    }
    rep(i,q)printf("%lld%c",ans[i]," \n"[i==q]);
    return 0;
}