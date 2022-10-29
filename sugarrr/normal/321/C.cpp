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
////////////////////////////

struct CentroidDecomposition{
    int N;
    vector<vector<int>>G;//G[i]i(vector)
    vector<vector<int>>T;//T[i]i(vector)
    vector<int>used,sz;//sz[i]i
    int r;
    void set(int n){
        N=n;
        G.resize(N);
        T.resize(N);
    }
    void addEdge(int a,int b){
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int calcSubtreeSize(int v,int p){
        sz[v]=1;
        for(auto u:G[v]){
            if(u==p||used[u])continue;
            sz[v]+=calcSubtreeSize(u,v);
        }
        return sz[v];
    }
    pair<int,int>findCentroid(int v,int p,int ov){
        pair<int,int>ret(N,-1);
        int mx=ov-sz[v];
        for(auto u:G[v]){
            if(u==p||used[u])continue;
            ret=min(ret,findCentroid(u,v,ov));
            mx=max(mx,sz[u]);
        }
        ret=min(ret,pair<int,int>(mx,v));
        return ret;
    }
    void dfs(int v,int p){
        calcSubtreeSize(v,-1);
        v=findCentroid(v,-1,sz[v]).second;
        used[v]=true;
        if(p==-1)r=v;
        else T[p].push_back(v);
        for(auto u:G[v])if(!used[u])dfs(u,v);
    }
    void decompose(){
        used.resize(N);
        sz.resize(N);
        dfs(1,-1);/*1
                   0-indexeddfs(0,-1)
                   */
    }
    inline int root()const{
        return r;
    }
    vector<int>&operator[](int i){
        return T[i];
    }
};
CentroidDecomposition ct;
//ct.set(N);
//for(a,b) ct.addEdge(a,b);
//ct.decompose();

/////////////////////////////////

int main(){fastio
    ll n;cin>>n;
    ct.set(n+1);
    rep(i,1,n-1){
        ll a,b;cin>>a>>b;
        ct.addEdge(a,b);
    }
    ct.decompose();
    ll ans[n+1];
    queue<ll>q;q.push(ct.root());
    ans[ct.root()]=0;
    while(!q.empty()){
        ll t=q.front();q.pop();
        for(auto x:ct.T[t]){
            ans[x]=ans[t]+1;
            q.push(x);
        }
    }
    rep(i,1,n)cout<<(char)('A'+ans[i])<<" ";
    
    
    return 0;
}