#include <iostream>
#include <vector>
using namespace std;
const int N = 200000 + 10;
vector<int> g[N];
int n,par[N],son[N],top[N],sz[N],dep[N],dis[N];
void pre(int u,int p){
    par[u]=p, sz[u]=1, dep[u]=dep[p]+1;
    int mx=0;
    for(auto v:g[u]){
        if(v==p)continue;
        pre(v,u); sz[u]+=sz[v];
        if(sz[v]>mx) mx=sz[v], son[u]=v;
    }
}
void dfs(int u,int p){
    top[u]=p;
    if(son[u]) dfs(son[u],p);
    for(auto v:g[u]){
        if(v==son[u]||v==par[u])continue;
        dfs(v,v);
    }
}
int solve(int u) {
    printf("s %d\n", u); fflush(stdout);
    int x; scanf("%d",&x); dis[x]=dis[u]-1;
    int t=x,v=x; while(son[t]) t=son[t];
    printf("d %d\n", t); fflush(stdout);
    scanf("%d",&x); dis[t]=x;
    while(v) {
        if( dis[u]-dis[t] == (dep[v]-dep[u]) - (dep[t]-dep[v]) ) break;
        v=son[v];
    }
    dis[v] = dis[t] - (dep[t] - dep[v]);
    if(dis[t] == dep[t] - dep[v]) return v;
    return solve(v);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    pre(1,1); dfs(1,1);
    printf("d 1\n"); fflush(stdout); 
    int x; scanf("%d",&x); dis[1]=x;
    if(x==0) {
        printf("! 1\n"); fflush(stdout); return 0;
    }
    printf("! %d\n", solve(1)); fflush(stdout);
}