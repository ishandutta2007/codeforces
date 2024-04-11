#include <iostream>
#include <vector>

using namespace std;
const int N = 200000 + 10;

vector<int> g[N];
int n,f[N][2],sz[N],leaf[N];
void dfs1(int u,int p){   
    sz[u] = 1;
    int mn = N, mx = 0;
    for(auto v: g[u]){
        if(v==p) continue;
        dfs1(v,u); 
        sz[u] += sz[v]; leaf[u] += leaf[v];
        mn = min(mn, leaf[v] - f[v][1]);
        mx = mx + f[v][0] - 1;
    }
    f[u][0] = leaf[u] - mn;
    f[u][1] = mx + 1;
    if (sz[u] == 1) {
        f[u][0]=f[u][1]=1;
        leaf[u] = 1;
    }
}
void dfs2(int u,int p){
    sz[u]=1;
    int sum=0,mn=N;
    for(auto v: g[u]) {
        if(v==p) continue;
        dfs2(v,u); sz[u]+=sz[v];
        sum += f[v][1];
        mn = min(mn, f[v][0]);
    }
    f[u][0] = sum; f[u][1] = mn;
    if (sz[u] == 1) {
        f[u][0]=f[u][1]=1;
        leaf[u] = 1;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs1(1,1); printf("%d ", f[1][0]);
    dfs2(1,1); printf("%d", f[1][0]);
}