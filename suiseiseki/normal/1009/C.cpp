#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
#define maxn 200005
const int mod=1e9+7;
#define eps 1e-5
#define pi acos(-1.0)

ll quickpow(ll a,ll b)
{
    ll ans=1;
    while(b){
        if(b&1){
            ans=ans*a;
        }
        a=a*a;
        b>>=1;
    }
    return ans;
}
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}




int main()
{
    //ios::sync_with_stdio(false);
     ll n,m;
     cin>>n>>m;
     ll ans=0;
     for(int i=0;i<m;i++){
        ll x,d;
        cin>>x>>d;
        if(d>=0){
            ans+=n*x+d*n*(n-1)/2;
        }
        else {
            if(n%2){
                ll t=(n+1)/2;
                ans+=n*x+2*d*t*(t-1)/2;
            }
            else {
                ll t=n/2;
                ans+=n*x+n*n*d/4;
            }
        }
     }
     printf("%.7lf\n",ans*1.0/n);
    return 0;
}