#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
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
////////////////////////////



int main(){fastio
    ll n;cin>>n;
    vector<l_l>v;
    ll c=0;
    rep(i,0,n-1){
        ll sz;cin>>sz;
        vector<ll>q;
        rep(j,0,sz-1){
            ll t;cin>>t;q.pb(t);
        }
        bool flag=false;
        if(sz>=2)rep(j,0,sz-2){
            if(q[j]<q[j+1])flag=true;
        }
        if(!flag){
            c++;
            v.pb(l_l(q[0],q[sz-1]));
        }
    }
    sort(v.begin(),v.end());
    ll ans=n*n-c*c;
    ll vs=v.size();
    rep(i,0,vs-1){
        ll add=vs-(lower_bound(v.begin(),v.end(),l_l(v[i].second+1,-inf))-v.begin());
        ans+=add;
    }
    cout<<ans<<endl;
    
    return 0;
}