#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAX_V = 100050;
const int MAX_LOG_V = 17;
int root = 0;
int n,a,b,k;

vector<int> G[MAX_V];
vector<int> V;
map<P, int> mp;

int cnt[MAX_V], res[MAX_V];
int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];
bool vis[MAX_V];

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    for(int i = 0; i < G[v].size(); i++){
        if(G[v][i] != p) dfs(G[v][i], v, d+1);
    }
}

void init(int V){
    dfs(root, -1, 0);

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

void dfs(int v, int p){
    vis[v] = 1;
    for(int nxt : G[v]){
        if(!vis[nxt]){
            dfs(nxt, v);
            cnt[v] += cnt[nxt];
        }
    }
    if(p != -1) res[mp[P(v,p)]] = cnt[v];
}

int main(){

    scanf("%d", &n);
    fill(cnt, cnt+n, 0);
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        mp[P(a,b)] = mp[P(b,a)] = i;
    }
    init(n);

    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        cnt[a]++, cnt[b]++, cnt[lca(a,b)] -= 2;
    }

    fill(vis, vis+n, 0);
    dfs(0,-1);
    for(int i = 0; i < n-1; i++) printf("%d ", res[i]);
}