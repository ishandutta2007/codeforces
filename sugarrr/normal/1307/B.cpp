//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int ll;
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
typedef pair<dd,dd> d_d;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
////////////////////////////

bool anspro(){
    ll n,x;cin>>n>>x;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    sort(a,a+n);
    rep(i,0,n-1){
        if(a[i]==x){
            cout<<1<<endl;return 0;
        }
    }
    
    ll y=a[n-1];
    ll ans=max(2,(x+y-1)/y);
    cout<<ans<<endl;
    return 0;
}


int main(){fastio
    ll q;cin>>q;
    while(q--){
        anspro();
    }
    
    return 0;
}