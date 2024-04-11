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

ll n;
#define N 5005
struct query{
    ll a,b,c;
    bool operator<(const query op)const{
        return c>op.c;
    }
};
ll ans[N];
vector<l_l>v[N];
ll ban[N][N];

#define MAX_V 5005
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


int main(){fastio
    cin>>n;
    rep(i,1,n-1){
        ll a,b;cin>>a>>b;
        v[a].pb(l_l(b,i));
        v[b].pb(l_l(a,i));
        G[a].pb(b);G[b].pb(a);
        ban[a][b]=ban[b][a]=i;
    }
    root=1;init(n+1);
    ll m;cin>>m;
    vector<query>que(m);
    rep(i,0,m-1){
        cin>>que[i].a>>que[i].b>>que[i].c;
    }
    SORT(que);
    for(auto qu:que){
        ll a=qu.a,b=qu.b,c=qu.c;
        vector<ll>jun;
        ll l=lca(a,b);
        vector<ll>va,vb;
        while(a!=l){
            va.pb(a);
            a=parent[0][a];
        }
        vb.pb(b);
        while(b!=l){
            b=parent[0][b];
            vb.pb(b);
        }
        reverse(vb.begin(),vb.end());
        for(auto x:va)jun.pb(x);
        for(auto x:vb)jun.pb(x);
        //for(auto x:jun)cout<<x<<" ";cout<<endl;
        ll js=jun.size();
        bool f=false;
        rep(i,0,js-2){
            ll x=jun[i],y=jun[i+1];
            
            if(ans[ban[x][y]]==0){
                ans[ban[x][y]]=c;
                f=true;
            }else if(ans[ban[x][y]]==c){
                f=true;
            }
            
        }
        if(!f){cout<<-1<<endl;return 0;}
    }
    rep(i,1,n-1){
        cout<<((ans[i]==0)?1:ans[i])<<" ";
    }
    
    return 0;
}