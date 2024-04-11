#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int N = 100050, INF = (int)1e9;
const int LOG_N = 17;
int root = 0;
int n,m,a,b;

vector<int> G[N];
int parent[LOG_N][N];
ll dp[N], sz[N], sdp[N], ssz[N];
int depth[N], par[N];

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    sz[v] = 1;
    dp[v] = 0;
    for(int nxt : G[v]){
        if(nxt != p) {
            dfs(nxt, v, d+1);
            sz[v] += sz[nxt];
            dp[v] += sz[nxt] + dp[nxt];
        }
    }
}

void init(int V){
    dfs(root, -1, 0);

    for(int k = 0; k+1 < LOG_N; k++){
        for(int v = 0; v < V; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]){int tmp = u; u = v; v = tmp;}
    for(int k = 0; k < LOG_N; k++){
        if((depth[v] - depth[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    if(u == v) return u;
    for(int k = LOG_N - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

int min_dis(int u, int v){
    int ca = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[ca];
}

void reroot(int v, int p, ll up_sz, ll up_dp) {
    ssz[v] = up_sz + sz[v];
    sdp[v] = up_sz + up_dp + dp[v];
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        ssz[v] -= sz[nxt];
        sdp[v] -= sz[nxt] + dp[nxt];
        reroot(nxt, v, ssz[v], sdp[v]);
        ssz[v] += sz[nxt];
        sdp[v] += sz[nxt] + dp[nxt];
    }
}

double calc_ans(int u, int ca, int v) {
    if(u != ca) return (double)dp[u] / sz[u];
    for(int k = LOG_N - 1; k >= 0; k--) {
        if(parent[k][v] != -1 && depth[parent[k][v]] > depth[u]) v = parent[k][v];
    }
    assert(depth[v] == depth[u] + 1);
    return (double)(sdp[u] - dp[v] - sz[v]) / (ssz[u] - sz[v]);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    init(n);
    reroot(0, -1, 0, 0);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        int ca = lca(u, v);
        double res = depth[u] + depth[v] - 2 * depth[ca] + calc_ans(u, ca, v) + calc_ans(v, ca, u);
        cout << fixed << setprecision(10) << res + 1 << "\n";
    }
}