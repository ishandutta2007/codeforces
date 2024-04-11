#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

struct edge {
    int to, d;
};

int n, m;
vector<edge> G[N];
int cyc = -1;
int vis[N], depth[N];

int dfs(int v, int dep) {
    vis[v] = -1;
    depth[v] = dep;
    for(const auto &e : G[v]) {
        if(vis[e.to] == -1) {
            int new_cyc = abs(dep + e.d - depth[e.to]);
            if(new_cyc != 0) {
                cyc = new_cyc;
                return -1;
            }
        }
        if(vis[e.to] == 0 && dfs(e.to, dep + e.d) == -1)
            return -1;
    }
    vis[v] = 1;
    return 0;
}

int dfs2(int v, int dep, int k) {
    vis[v] = 1;
    depth[v] = dep;
    for(const auto &e : G[v]) {
        if(vis[e.to]) {
            if((dep + e.d + k) % k != depth[e.to]) return -1;
        }
        else if(dfs2(e.to, (dep + e.d + k) % k, k) == -1) return -1;
    }
    return 1;
}

bool check(int k) {
    fill(vis, vis + n, 0);
    for(int i = 0; i < n; i++) {
        if(!vis[i] && dfs2(i, 0, k) == -1) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back({b, 1});
        G[b].push_back({a, -1});
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i] && dfs(i, 0) == -1) break;
    }
    if(cyc == -1) return cout << n << endl, 0;
    int res = 1;
//    cout << cyc << endl;
    for(int i = 1; i * i <= cyc; i++) {
        if(cyc % i != 0) continue;
        if(check(i)) res = max(i, res);
        if(check(cyc / i)) res = max(cyc / i, res);
    }
    cout << res << endl;

}