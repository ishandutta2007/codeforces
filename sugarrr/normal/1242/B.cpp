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

class UnionFind {
public:
    vector < ll > par; // 
    vector < ll > siz; // (1 )
    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1);
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 
    }
    // Member Function
    // Find
    ll root(ll x) { // 
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x  x 
        }
        return x;
    }
    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }
    bool issame(ll x, ll y) { // 
        return root(x) == root(y);
    }
    ll size(ll x) { // 
        return siz[root(x)];
    }
};
/////////////////////////////////////

int main(){fastio
    ll n,m;cin>>n>>m;
    if(n<=5000){
        bool f[n+1][n+1];memset(f,true,sizeof(f));
        rep(_,1,m){
            ll a,b;cin>>a>>b;
            f[a][b]=f[b][a]=false;
        }
        UnionFind u(n+1);
        //u.init(n+1);
        rep(i,1,n){
            rep(j,i+1,n){
                if(f[i][j])u.merge(i,j);
            }
        }
        ll ans=0;
        rep(i,1,n){
            if(u.root(i)==i)ans++;
        }
        cout<<ans-1<<endl;return 0;
    }
    vector<ll>v[n+1];
    rep(_,1,m){
        ll a,b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    vector<ll>lar;
    UnionFind u(n+1);
    u.init(n+1);
    rep(i,1,n){
        if(v[i].size()<=n-100){
            lar.pb(i);
        }else{
            bool f[n+1];memset(f,false,sizeof(f));
            for(auto x:v[i])f[x]=true;
            rep(j,1,n){
                if(i==j)continue;
                if(!f[j]){
                    u.merge(i,j);
                }
            }
        }
    }
    ll lars=lar.size();
    rep(i,0,lars-2){
        u.merge(lar[i],lar[i+1]);
    }
    ll ans=0;
    rep(i,1,n){
        if(u.root(i)==i)ans++;
    }
    cout<<ans-1<<endl;
    
    return 0;
}