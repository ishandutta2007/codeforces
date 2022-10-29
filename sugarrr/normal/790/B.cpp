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
#define rrep(i,r,l) for(ll i=r;i>=l;i--)
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
//#define endl "\n"  //
#define SORT(v) sort(v.begin(),v.end())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define POSL(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define POSU(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
template<class T,class S>
inline bool chmax(T &a, S b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T,class S>
inline bool chmin(T &a, S b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

void mod_print(ll k){
    ll P=50000;
    rep(y,1,P){
        ll x=mod(y*k);
        
        if(abs(x)<=P||x+P>=i_7){
            if(x+P>=i_7){
                x-=i_7;
            }
            cout<<x<<"/"<<y<<endl;
            //cout<<setprecision(5)<<(dd)x/(dd)y;
            return;
        }
    }
    cout<<"nun"<<endl;
}
#define all(c) c.begin(),c.end()
typedef vector<ll> vl;
//////////////////////////


ll n,k;
#define N 200005
vector<ll>v[N];
ll ans=0;
ll sz[N];
bool used[N];

void szdfs(ll id,ll par){
    sz[id]=1;
    for(auto x:v[id]){
        if(x==par||used[x])continue;
        szdfs(x,id);
        sz[id]+=sz[x];
    }
}
ll centroid(ll id,ll par,ll total){
    for(auto x:v[id]){
        if(x==par||used[x])continue;
        if(sz[x]*2>total){
            return centroid(x,id,total);
        }
    }
    return id;
}
ll dis[N];
void dfs(map<ll,l_l>&mp,vector<ll>&t,ll id,ll par,ll d){
    dis[id]=d;
    mp[d%k].fi++;
    mp[d%k].se+=d/k;
    t.pb(id);
    for(auto x:v[id]){
        if(x==par||used[x])continue;
        dfs(mp,t,x,id,d+1);
    }
}
void solve(ll id,ll par){
    szdfs(id,par);
    id=centroid(id,par,sz[id]);
    used[id]=true;
    map<ll,l_l>MP;
    vector<ll>T;
    dis[id]=0;
    for(auto x:v[id]){
        if(x==par||used[x])continue;
        map<ll,l_l>mp;
        vector<ll>t;
        dfs(mp,t,x,id,1);
        for(auto u:t){
            ll a=dis[u]%k;
            ll b=dis[u]/k;
            for(auto y:mp){
                ans-=y.se.fi*b+y.se.se;
                if(a+y.fi>k){
                    ans-=2*y.se.fi;
                }else if(a+y.fi>0){
                    ans-=y.se.fi;
                }
            }
        }
        for(auto u:mp){
            MP[u.fi].fi+=u.se.fi;
            MP[u.fi].se+=u.se.se;
        }
        T.insert(T.end(),t.begin(),t.end());
    }
    for(auto u:T){
        ll a=dis[u]%k;
        ll b=dis[u]/k;
        for(auto y:MP){
            ans+=y.se.fi*b+y.se.se;
            if(a+y.fi>k){
                ans+=2*y.se.fi;
            }else if(a+y.fi>0){
                ans+=y.se.fi;
            }
        }
        ans+=2*((dis[u]+k-1)/k);
    }
   // cout<<id<<" "<<ans<<endl;
    for(auto x:v[id]){
        if(x==par||used[x])continue;
        solve(x,id);
    }
}

int main(){fastio
    cin>>n>>k;
    rep(i,1,n-1){
        ll a,b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    solve(1,-1);
    cout<<ans/2<<endl;
    return 0;
}