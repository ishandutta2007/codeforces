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

#define N 100005
//#define N 5
ll n;
vector<ll>v[N];
ll a[N];
ll sz[N];
bool used[N];

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
#define M 21
ll b[M][N];
ll sum[M][N];
ll solcnt[M];
void dfs(ll id,ll par,vector<ll>&t){
    t.pb(id);
    rep(x,0,M-1){
        sum[x][id]=sum[x][par]^b[x][id];
    }
    for(auto x:v[id]){
        if(x==par||used[x])continue;
        dfs(x,id,t);
    }
}
void solve(ll id,ll par){
    
    szdfs(id,par);
    id=centroid(id,par,sz[id]);
    //cout<<id<<endl;
    rep(x,0,M-1)sum[x][id]=0;
    vector<ll>T;T.pb(id);
    ll MP[M][2];memset(MP,0,sizeof(MP));
    rep(x,0,M-1)MP[x][0]++;
    used[id]=true;
    for(auto x:v[id]){
        if(x==par||used[x])continue;
        vector<ll>t;
        ll mp[M][2];memset(mp,0,sizeof(mp));
        dfs(x,id,t);
        for(auto u:t){
            rep(z,0,M-1)mp[z][sum[z][u]]++;
        }
        for(auto u:t){
            rep(z,0,M-1)solcnt[z]-=mp[z][1^sum[z][u]^b[z][id]];
        }
        T.insert(T.end(),t.begin(),t.end());
        rep(z,0,M-1){
            rep(k,0,1){
                MP[z][k]+=mp[z][k];
            }
        }
    }
    for(auto u:T){
        rep(z,0,M-1)solcnt[z]+=MP[z][1^sum[z][u]^b[z][id]];
    }
    
    for(auto x:v[id]){
        if(x==par||used[x])continue;
        solve(x,id);
    }
    rep(z,0,M-1)solcnt[z]-=b[z][id];
    //return solcnt/2;
}
int main(){fastio
    scanf("%lld",&n);
    rep(i,1,n)scanf("%lld",&a[i]);
    rep(i,1,n-1){
        ll a,b;scanf("%lld %lld",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    rep(z,0,M-1){
        rep(j,1,n){
            if(a[j]&(1ll<<z))b[z][j]=1;
            else b[z][j]=0;
        }
    }
    solve(1,-1);
    ll ans=0;
    
    rep(i,0,M-1)ans+=(1ll<<i)*solcnt[i];
    ans/=2;
    rep(i,1,n)ans+=a[i];
    printf("%lld\n",ans);
    return 0;
}