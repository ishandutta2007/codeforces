#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAX_V = 100050;
const int MAX_LOG_V = 17;
int root = 0;
int n,m,a,b;

vector<int> G[MAX_V];

int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V], subsum[MAX_V], vis[MAX_V];

void dfs(int v){
    vis[v] = 1;
    subsum[v] = 1;
    for(int nxt : G[v]){
        if(!vis[nxt]){
            dfs(nxt);
            subsum[v] += subsum[nxt];
        }
    }
}

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    for(int i = 0; i < G[v].size(); i++){
        if(G[v][i] != p) dfs(G[v][i], v, d+1);
    }
}

void init(int V){
    fill(vis, vis + V, 0);
    dfs(root, -1, 0);
    dfs(root);

    for(int k = 0; k+1 < MAX_LOG_V; k++){
        for(int v = 0; v < V; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]){int tmp = u; u = v; v = tmp;}
    for(int k = 0; k < MAX_LOG_V; k++){
        if((depth[v] - depth[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    if(u == v) return u;
    for(int k = MAX_LOG_V - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

int getsub(int t, int v){
    int cur = v;
    for(int i = 0; i < MAX_LOG_V; i++){
        if(t % 2) cur = parent[i][cur];
        t /= 2;
    }
    return cur;
}

int getres(int k, int v){
    return subsum[getsub(k,v)] - subsum[getsub(k-1,v)];
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    init(n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b); a--,b--;
        if((depth[a] + depth[b]) % 2 == 1) printf("0\n");
        else if(depth[a] == depth[b]){
            int lcai = lca(a,b);
            int len = depth[a] - depth[lcai];
            if(len == 0) printf("%d\n", n);
            else printf("%d\n", n - subsum[getsub(len-1,a)] - subsum[getsub(len-1,b)]);
        }
        else{
            int lcai = lca(a,b);
            int len = depth[a] + depth[b] - 2 * depth[lcai];
            printf("%d\n", depth[a] > depth[b] ? getres(len/2, a) : getres(len/2, b));
        }
    }


}