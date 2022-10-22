#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int N = (int)1e6 + 50, INF = (int)1e9;
const int LOG_N = 20;
int root = 0;
int n;

vector<int> G[N];
int parent[LOG_N][N];
int depth[N], par[N];

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    for(int nxt : G[v]){
        if(nxt != p) dfs(nxt, v, d+1);
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

int q;
int qr[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i <= 3; i++) G[0].push_back(i);
    n = 4;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> qr[i]; qr[i]--;
        int u = n++, v = n++;
        G[qr[i]].push_back(u);
        G[qr[i]].push_back(v);
    }
    init(n);
    int u = 1, v = 3, d = 2;
    for(int i = 0; i < q; i++) {
        for(int x : G[qr[i]]) {
            int d_ux = min_dis(u, x);
            if(d_ux > d) d = d_ux, v = x;
            int d_vx = min_dis(v, x);
            if(d_vx > d) d = d_vx, u = x;
        }
        cout << d << "\n";
    }
}