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
///////////////////////////

#define N 50005
ll n,k;
vector<ll>v[N];
bool used[N];
ll sz[N];
ll szdfs(ll id,ll par){
    sz[id]=1;
    for(auto x:v[id]){
        if(x==par||used[x])continue;
        sz[id]+=szdfs(x,id);
    }
    return sz[id];
}
ll centroid(ll id,ll par,ll total){
    for(auto x:v[id]){
        if(x==par||used[x])continue;
        if(sz[x]*2>total)return centroid(x,id,total);
    }
    return id;
}
ll ans=0;
ll dis[N];
void dfs(ll id,ll par,vector<ll>&t,ll d,map<ll,ll>&mp){
    t.pb(id);
    mp[d]++;
    dis[id]=d;
    for(auto x:v[id]){
        if(x==par||used[x])continue;
        dfs(x,id,t,d+1,mp);
    }
}
void solve(ll id,ll par){
    szdfs(id,par);
    id =centroid(id,par,sz[id]);
    dis[id]=0;
    vector<ll>T;T.pb(id);
    map<ll,ll>MP;MP[0]++;
    used[id]=true;
    for(auto x:v[id]){
        if(x==par||used[x])continue;
        vector<ll>t;
        map<ll,ll>mp;
        dfs(x,id,t,1,mp);
        for(auto u:t){
            ans-=mp[k-dis[u]];
        }
        for(auto u:mp){
            MP[u.fi]+=u.se;
        }
        T.insert(T.end(),t.begin(),t.end());
    }
    
    for(auto u:T){
        ans+=MP[k-dis[u]];
    }
    for(auto x:v[id]){
        if(x==par||used[x])continue;
        solve(x,id);
    }
}

int main(){fastio
    cin>>n>>k;
    rep(i,1,n-1){
        ll a,b;cin>>a>>b;
        v[a].pb(b);v[b].pb(a);
    }
    solve(1,-1);
    cerr<<ans<<endl;
    cout<<ans/2<<endl;
    
    return 0;
}