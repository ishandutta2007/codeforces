
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> namespace mp = boost::multiprecision; //mp::cpp_int
using namespace std;
typedef long long ll;
//#define i_7 (ll)(1E9+7)
#define i_7 998244353

#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////

#define N 300000
struct edge{ll u,v,cost;};
vector<l_l >es[N];
//ll mincost[N];
bool used[N];
ll V;
ll ans=0;
ll a;
ll spe[N];
auto comp = [](edge left, edge right) { return (left.cost) > (right .cost);};
priority_queue <edge,vector<edge>,decltype(comp)> p(comp);


ll k;
void prim(){
    ll count=1;
    rep(i,0,V-1){
        // mincost[i]=inf;
        used[i]=false;
    }
    // mincost[a]=0;
    used[a]=true;
    for(auto x:es[a]){
        edge e;e.u=a;e.v=x.first;e.cost=x.second;
        p.push(e);
    }
    while(1){
        edge t;
        ll next=N-1;
        while(!p.empty()){
            t=p.top();p.pop();
            if(!used[t.u]||!used[t.v]){
                if(used[t.u])next=t.v;
                else next=t.u;
                break;
            }
        }
        if(next==N-1)break;
        used[next]=true;
        for(auto x:es[next]){
            edge e;e.u=next;e.v=x.first;e.cost=x.second;
            p.push(e);
        }
        ans=max(ans,t.cost);
        if(spe[next]==1)count++;
        if(count==k)break;
        
    }
}

int main(){
    ll e;cin>>V>>e>>k;
    memset(spe,0,sizeof(spe));
    rep(i,0,k-1){
        cin>>a;a--;
        spe[a]=1;
    }
    rep(i,0,e-1){
        edge e;
        cin>>e.u>>e.v>>e.cost;
        e.u--;e.v--;
        es[e.u].pb(l_l(e.v,e.cost));
        es[e.v].pb(l_l(e.u,e.cost));
    }
    prim();
    rep(i,0,k-1)cout<<ans<<" ";
    
    return 0;
}