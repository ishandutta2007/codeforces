
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
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
long double EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////////////////


int main(){fastio;
    ll n,m;cin>>n>>m;
    vector<ll>v[n+1];
    rep(z,1,m){
        ll a,b;cin>>a>>b;
        if(a>b)b+=n;
        v[a].pb(b-a);
    }
    rep(i,1,n)sort(v[i].begin(),v[i].end());
    rep(s,1,n){
        ll ans=0;
        rep(i,s,n){
            if(v[i].size()==0)continue;
            ll k=(v[i].size()-1)*n+v[i][0]+i-s;
            Max(ans,k);
        }
        rep(i,1,s-1){
            if(v[i].size()==0)continue;
            ll k=(v[i].size()-1)*n+v[i][0]+i+n-s;
            Max(ans,k);
        }
        cout<<ans<<" ";
    }
    
    return 0;
}