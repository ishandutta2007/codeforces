//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
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
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////

#define N 200005
ll n,k;
vector<ll>v[N];
ll sz[N];
ll dep[N];

void dfs(ll id,ll par){
    sz[id]=1;
    for(auto x:v[id]){
        if(x==par)continue;
        dep[x]=dep[id]+1;
        dfs(x,id);
        sz[id]+=sz[x];
        
    }
}

int main(){fastio
    cin>>n>>k;
    rep(i,1,n-1){
        ll a,b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1,-1);
    //rep(i,1,n)cout<<sz[i]<<" ";cout<<endl;
    //rep(i,1,n)cout<<dep[i]<<" ";cout<<endl;
    ll a[n];
    rep(i,1,n){
        a[i-1]=dep[i]-(sz[i]-1);
    }
    sort(a,a+n);
    //rep(i,1,n)cout<<a[i]<<" ";cout<<endl;
    ll ans=0;
    rep(i,n-k,n-1){
        ans+=a[i];
    }
    cout<<ans<<endl;
    
    
    return 0;
}