#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int N = 100050, INF = (int)1e9, mod = (int)1e9 + 7, M = (int)1e6 + 50;
const int LOG_N = 17;
int root = 0;
int n,m,a,b;
ll res = 0;

struct edge {
    int to, tp;
};


vector<edge> G[N];
int parent[LOG_N][N];
int depth[N], par[N];
int ordin[N], uordin[N];

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    for(auto e : G[v]){
        if(e.to != p) dfs(e.to, v, d+1);
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

int pw[M];


P dfs2(int v, int p) {
    int in = 0, uin = 0;
    for(auto e : G[v]) {
        if(e.to == p) continue;
        P pn = dfs2(e.to, v);
        if(e.tp == 0) {
            res += (pw[pn.first] - 1);
        }
        else if(e.tp == 1) {
            res += (pw[pn.second] - 1);
        }
        res %= mod;
        in += pn.first;
        uin += pn.second;
    }
    in += ordin[v];
    uin += uordin[v];
    return {in, uin};
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pw[0] = 1;
    for(int i = 1; i < M; i++) pw[i] = pw[i-1] * 2 % mod;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        if(c == 0) {
            G[a].push_back({b, -1});
            G[b].push_back({a, -1});
        }
        else {
            G[a].push_back({b, 0});
            G[b].push_back({a, 1});
        }
    }
    dfs(0, -1, 0);
    init(n);
    cin >> m;
    vector<int> seq(m + 1);
    seq[0] = 0;
    for(int i = 1; i <= m; i++) cin >> seq[i], seq[i]--;
    for(int i = 0; i < m; i++) {
        int a = seq[i], b = seq[i+1];
        int ca = lca(a, b);
        ordin[a]++, ordin[ca]--;
        uordin[b]++, uordin[ca]--;
    }
    dfs2(0, -1);
    cout << (res % mod + mod) % mod << endl;


}