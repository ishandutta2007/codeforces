#include <bits/stdc++.h>
//#include "bits/stdc++.h"
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

ll cal(vector<ll>&v){
    ll sum=v.size();
    SORT(v);
    ll mx=0;
    rep(i,0,sum-1){
        ll c=1;
        while(i+1<=sum-1 &&v[i]==v[i+1]){
            i++;c++;
        }
        Max(mx,c);
    }
    return sum-mx;
}

bool anspro(){
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    ll a[n];memset(a,0,sizeof(a));
    ll ans=0;
    UnionFind u(n);
    rep(i,0,k-1){
        for(ll j=i+k;j<=n-1;j+=k){
            u.merge(i,j);
        }
    }
    rep(i,0,n/2){
        u.merge(i,n-1-i);
    }
    vector<ll>v[n];
    rep(i,0,n-1){
        v[u.root(i)].pb(s[i]-'a');
    }
    rep(i,0,n-1){
        if(v[i].size()>=2){
            ans+=cal(v[i]);
        }
    }
    
    /*ll id=1;
    rep(i,0,n-1){
        if(a[i]==0){
            vector<ll>v;
            queue<ll>q;q.push(i);a[i]=id;
            while(!q.empty()){
                ll t=q.front();q.pop();
                v.pb(s[t]-'a');
                if(a[n-1-t]==0){q.push(n-1-t);a[n-1-t]=id;}
                for(ll x=t+k;x<=n-1;x+=k){
                    if(a[x]==0){q.push(x);a[x]=id;}
                }
                for(ll x=t-k;x>=0;x-=k){
                    if(a[x]==0){q.push(x);a[x]=id;}
                }
            }
            id++;
            ans+=cal(v);
        }
    }*/
    cout<<ans<<endl;
    return 0;
}
int main(){fastio
    ll qu;cin>>qu;
    while(qu--){
        anspro();
    }
    
    return 0;
}