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


bool comp(l_l a,l_l b){
    return a.second<=b.second;
}

int main(){fastio
    ll n;cin>>n;
    l_l a[n];
    rep(i,0,n-1){
        ll b,c;cin>>b>>c;
        a[i]=l_l(b-c,b+c);
    }
    sort(a,a+n,comp);
    ll bound=a[0].second;
    ll ans=1;
    rep(i,1,n-1){
        if(bound<=a[i].first){
            ans++;
            bound=a[i].second;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}