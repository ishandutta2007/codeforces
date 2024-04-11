#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 400000 + 10;
int n;
int in[N],out[N];
vector<LL> v;
int id(LL x){
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
vector< pair<int,LL> > g[N];
vector<int> dag[N];
struct Nod {
    int u;LL dis;
    bool operator<(const Nod&o)const{
        return dis>o.dis;
    }
};
void dijkstra(int s,int t) {
    priority_queue<Nod> q; 
    LL dis[N]; for(int i=0;i<N;i++) dis[i]=-1;
    q.push((Nod){s,0}); dis[s]=0;
    while(q.size()) {
        Nod nod = q.top(); q.pop();
        int u=nod.u;
        if(nod.dis > dis[u]) continue;
        for(auto e: g[u]) {
            int v = e.first;
            if(dis[v]==-1 || dis[u]+e.second < dis[v]) {
                dis[v] = dis[u]+e.second; 
                q.push((Nod){v,dis[v]});
            }
        }
    }
    for(int u=1;u<=v.size();u++){
        for(auto e: g[u]) {
            if(dis[e.first] == dis[u] + e.second) {
                dag[u].push_back(e.first);
            }
        } 
    }
    //printf("$ %lld\n", dis[t]);
}
LL dp[N],vis[N];
void dfs(int u){
    if(vis[u]) return;
    vis[u]=1; dp[u]=0;
    for(auto v: dag[u]) {
        dfs(v);
        (dp[u]+=dp[v])%=MOD;
    }
    if(u == v.size()) {
        dp[u]=1;
    }
}
const LL inf = 1e12;
void add(int x,int y,LL w){
    //printf("%d->%d, %lld\n", x,y,w);
    g[x].push_back(make_pair(y,w));
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&out[i],&in[i]);
        v.push_back(in[i]); v.push_back(out[i]);
    }
    LL s=0, t=inf;
    v.push_back(s); v.push_back(t);
    sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()), v.end());
    s=id(s),t=id(t);

    for(int i=1;i<=n;i++){
        add(id(in[i]),id(out[i]),0);
    }
    for(int i=s;i<t;i++){
        add(i,i+1,v[i]-v[i-1]);
    }
    LL mnout=inf,mxin=-inf;
    for(int i=1;i<=n;i++){
        mxin=max(mxin,(LL)in[i]);
        mnout=min(mnout,(LL)out[i]);
    }   
    set<int> A,B;
    for(int i=1;i<=n;i++){
        if(in[i]<mnout) {
            A.insert(id(in[i]));
        } 
        if(out[i]>mxin) {
            B.insert(id(out[i]));
        }
    }
    //for(auto x: A) add(s,x,0);
    for(auto x: B) add(x,t,0);
    dijkstra(s,t);
    dfs(s);
    cout<<dp[s]<<endl;
}