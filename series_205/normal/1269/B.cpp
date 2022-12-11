#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

ll n,m;
ll a[2000],b[2000],ans=1e18;

int main(){
    cin>>n>>m;
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    rep(i,n){
        ll x=(b[0]+m-a[i])%m;
        bool ok=true;
        rep(j,n){
            if(b[j]!=(a[(i+j)%n]+x)%m)ok=0;
        }
        if(ok)ans=min(ans,x);
    }
    cout<<ans<<endl;
}