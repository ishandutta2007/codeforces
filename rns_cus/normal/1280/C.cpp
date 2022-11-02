#include <bits/stdc++.h>
using namespace std;

#define N 200100

int n, K, sz[N];
typedef pair <int, int> pii;
vector <pii> adj[N];
typedef long long ll;

ll G, B;
pair <int, ll> rt[N];

void dfs(int u, int pa = 0) {
    sz[u] = 1;
    for (auto p : adj[u]) {
        int v = p.first, w = p.second;
        if (v == pa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] & 1) G += w;
        B += 1ll * min(sz[v], n - sz[v]) * w;
        rt[v] = make_pair(u, w);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &K); n = 2 * K;
        G = B = 0;
        for (int i = 1; i <= n; i ++) adj[i].clear();
        for (int i = 1, u, v, w; i < n; i ++) {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        rt[1] = make_pair(1, 0);
        dfs(1);
        printf("%I64d %I64d\n", G, B);
    }
    return 0;
}