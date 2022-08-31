#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
typedef long long ll;
const double eps=1e-9;
const int N=1e6+5;
ll a[N];int n;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%lld",a+i);
    ll ans=0;
    rep(i,n)ans=gcd(ans,a[i]);
    ll ret=1;
    for(int i=2;i<=1e6;++i)if(ans%i==0){
        ll cnt=0;
        while(ans%i==0)++cnt,ans/=i;
        ret*=cnt+1;
    }
    if(ans>1)ret*=2;
    printf("%lld\n",ret);
    return 0;
}