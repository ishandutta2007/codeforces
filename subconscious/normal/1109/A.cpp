#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fxaa
#define y0 fxbb
#define x1 fxcc
#define y1 fxdd
#define st first
#define nd second
#define eb emplace_back
using namespace std;
using ll=long long;
using ld=long double;
constexpr int N=2e6+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
int a[N],t[2][N],n,m;
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",a+i);
    rep(i,n)a[i]^=a[i-1];
    ll ans=0;
    for(int i=0;i<=n;++i)
        ans+=t[i%2][a[i]],++t[i%2][a[i]];//,printf("%d\n",a[i]);
    printf("%lld\n",ans);
    return 0;
}