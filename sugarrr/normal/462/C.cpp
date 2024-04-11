#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;

#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
///////////////////////////////////////




int main(){fastio
    
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    sort(a,a+n);
    if(n==1){
        cout<<a[0]<<endl;
    }else if(n==2){
        cout<<2*(a[0]+a[1])<<endl;
    }else{
        ll ans=0;
        rep(i,0,n-1){
            ans+=min((i+2),n)*a[i];
        }
        cout<<ans<<endl;
    }
    
    
    return 0;
}