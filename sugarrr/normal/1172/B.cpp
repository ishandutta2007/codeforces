//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int LL;
typedef long double dd;
//#define i_7 (ll)(1E9+7)
#define i_7 998244353
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



ll po(ll i,ll p){
    if(p==0)return 1;
    else{
        i=mod(i);
        if(p==1)return i;
        if(p%2==0)return po(mod(i*i),p/2);
        return mod(i*po(i,p-1));
    }
}
ll bunbo(ll n){
    return po(n,i_5);
}


#define N 2000004
ll kai[N];
ll kai2[N];
void calc(){
    kai[0]=1;
    kai2[0]=1;
    rep(i,1,N-1){
        kai[i]=mod(kai[i-1]*i);
    }
    kai2[N-1]=po(kai[N-1],i_5);
    for(ll i=N-2;i>=0;i--){
        kai2[i]=mod(kai2[i+1]*(i+1));
    }
}
ll comb(ll n,ll k){
    if(n<k)return 0;
    if(n==0)return 1;
    return mod(mod(kai[n]*kai2[n-k])*kai2[k]);
}


#define Z 200005
ll dp[Z];

vector<ll>v[Z];
void dfs(ll id,ll par){
    dp[id]=1;
    if(id!=1){
        ll cnt=1;
        for(auto x:v[id]){
            if(x==par)continue;
            dfs(x,id);
            dp[id]=mod(dp[id]*dp[x]);
            cnt++;
        }
        dp[id]=mod(dp[id]*kai[cnt]);
    }else{
        ll cnt=0;
        for(auto x:v[id]){
            if(x==par)continue;
            dfs(x,id);
            dp[id]=mod(dp[id]*dp[x]);
            cnt++;
        }
        dp[id]=mod(dp[id]*kai[cnt]);
    }
}
int main(){fastio
    calc();
    
    ll n;cin>>n;
    rep(i,1,n-1){
        ll a,b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1,-1);
    //rep(i,1,n)cout<<dp[i]<<" ";cout<<endl;
    cout<<mod(dp[1]*n)<<endl;
    
    return 0;
}