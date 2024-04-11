#include <bits/stdc++.h>
//#include "bits/stdc++.h"
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
#define endl "\n"
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
//template<class T>void max(T a,T b){if(a<b)return b;else return a;}
//template<class T>void min(T a,T b){if(a>b)return b;else return a;}
//template<class T>bool Max(T&a, T b){if(a < b){a = b;return 1;}return 0;}
//template<class T>bool Min(T&a, T b){if(a > b){a = b;return 1;}return 0;}

//////////////////////////

#define N 200005
ll n,q;
vector<ll>v[N];
ll par[N];
vector<ll>chi[N];
ll dep[N];

void dfs(ll id){
    for(auto x:v[id]){
        if(x==par[id])continue;
        par[x]=id;
        chi[id].pb(x);
        dep[x]=dep[id]+1;
        dfs(x);
    }
}

#define MAX_V 200005
#define MAX_LOGV 30
vector<int>G[MAX_V];
int root;//
int parent[MAX_LOGV][MAX_V];//2^k(-1)
int depth[MAX_V];
void dfs(int v,int p,int d){
    parent[0][v]=p;
    depth[v]=d;
    for(auto x:G[v]){
        if(x!=p)dfs(x,v,d+1);
    }
}
void init(int V){
    //parent[0]depth
    dfs(root,-1,0);
    //parent
    rep(k,0,MAX_LOGV-2){
        rep(v,0,V-1){
            if(parent[k][v]<0)parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}
//uvLCA
int lca(int u,int v){
    //uv
    if(depth[u]>depth[v])swap(u,v);
    rep(k,0,MAX_LOGV-2){
        if((depth[v]-depth[u])>>k&1){
            v=parent[k][v];
        }
    }
    if(u==v)return u;
    for(int k=MAX_LOGV-1;k>=0;k--){
        if(parent[k][u]!=parent[k][v]){
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}

////////////////////////////////////////

bool anspro(){
    ll k;cin>>k;
    vector<ll>a(k);
    ll ma=0;
    rep(i,0,k-1){
        cin>>a[i];
        if(dep[a[ma]]<dep[a[i]])ma=i;
    }
    
    rep(i,0,k-1){
        ll p=lca(a[i],a[ma]);
        if(dep[p]+2<=dep[a[i]]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    
    cout<<"YES"<<endl;
    return 0;
}

int main(){fastio
    cin>>n>>q;
    rep(i,1,n-1){
        ll a,b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(1);
    root=1;
    init(n+1);
    
    
    //rep(i,1,n)cout<<dep[i]<<" ";cout<<endl;
    while(q--){
        anspro();
        
    }
    return 0;
}