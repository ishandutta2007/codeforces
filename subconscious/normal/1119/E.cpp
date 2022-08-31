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
int a[N],n;
ll ans,cur;
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",a+i);
    cur=0;
    rep(i,n){
        ll fk=min(cur,1ll*a[i]/2);
        ans+=fk;cur-=fk;a[i]-=fk*2;
        ans+=a[i]/3;a[i]%=3;
        cur+=a[i];a[i]=0;
    }
    printf("%lld\n",ans);
    return 0;
}