
//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

/*
#include "boost/multiprecision/cpp_int.hpp"
#include "boost/multiprecision/cpp_dec_float.hpp"
namespace mp = boost::multiprecision;
typedef mp::cpp_int LL;
typedef mp::number<mp::cpp_dec_float<1024>> DD;// 1024(TLE)
*/

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
#define endl "\n"
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

void mod_print(ll k){
    ll P=1000;
    rep(y,1,P){
        ll x=mod(y*k);
        if(x+P>=i_7){
            x-=i_7;
        }
        if(abs(x)<=P){
            cout<<x<<"/"<<y<<endl;
            return;
        }
    }
    cout<<"nun"<<endl;
}
#define all(c) c.begin(),c.end()
//////////////////////////

void no(){
    cout<<-1<<endl;
    exit(0);
}

int main(){fastio
    ll n,m;cin>>n>>m;
    vector<ll>v[n+1];
    rep(i,1,m){
        ll a,b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    ll a[n+1];
    l_l t[n];
    rep(i,0,n-1){
        cin>>t[i].fi;
        t[i].se=i+1;
        a[i+1]=t[i].fi;
    }
    sort(t,t+n);
    rep(i,0,n-1){
        set<ll>s;
        ll pos=t[i].se;
        for(auto x:v[pos]){
            if(a[x]==a[pos]){
                no();
            }
            if(a[x]<a[pos])s.insert(a[x]);
        }
        if(s.size()!=a[pos]-1){
            no();
        }
    }
    rep(i,0,n-1)cout<<t[i].se<<" ";
    cout<<endl;
    
    
    return 0;
}