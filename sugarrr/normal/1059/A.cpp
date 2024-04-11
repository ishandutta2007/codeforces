#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
const double EPS=1E-8;
////////////////////////////////////////


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    
    ll n,l,a;cin>>n>>l>>a;
    vector<l_l>v;
    rep(i,0,n-1){
        ll t,s;cin>>t>>s;
        v.pb(l_l(t,t+s));
    }
    sort(v.begin(),v.end());
    ll ans=0;
    if(v.size()==0){
        ans=l/a;
    }else if(v.size()==1){
        ans=v[0].first/a+(l-v[0].second)/a;
    }else{
        ans=v[0].first/a+(l-v[n-1].second)/a;
        rep(i,1,n-1){
            ans+=(v[i].first-v[i-1].second)/a;
        }
    }
    cout<<ans<<endl;
    return 0;
}