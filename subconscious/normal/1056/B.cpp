#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuckyzx
#define y0 fuckyxc
#define x1 fuckxzc
#define y1 fucxyzc
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e6+5,MOD=1e9+7;
const ld eps=1e-12;
int c[N],n,m;
int main(){
    scanf("%d%d",&n,&m);
    rep(i,m)++c[1ll*i*i%m];
    for(int i=0;i<m;++i)c[i]*=n/m;
    rep(i,n%m)++c[1ll*i*i%m];
    ll ans=0;
    for(int i=0;i<m;++i)ans+=1ll*c[i]*c[(m-i)%m];
        printf("%lld\n",ans);
    return 0;
}