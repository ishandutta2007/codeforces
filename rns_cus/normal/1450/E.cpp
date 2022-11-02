#include <bits/stdc++.h>
using namespace std;

#define N 2020

int n, m, d[N];
typedef pair <int, int> pii;
const int inf = 1e9;
vector <pii> adj[N];

queue <int> Q;
bool inq[N];

bool solve(int x) {
    for (int i = 1; i <= n; i ++) d[i] = inf, inq[i] = 0;
    while (!Q.empty()) Q.pop();
    Q.push(x);
    d[x] = 0, inq[x] = 1;
    for (int runs = 0; runs < n; runs ++) {
        int sz = Q.size();
        if (!sz) return 1;
        while (sz --) {
            x = Q.front(), Q.pop();
            inq[x] = 0;
            for (auto p : adj[x]) {
                int y = p.first, z = p.second;
                if (d[y] <= d[x] + z) continue;
                d[y] = d[x] + z;
                if (!inq[y]) Q.push(y), inq[y] = 1;
            }
        }
    }
    return Q.empty();
}

int col[N];

void dfs(int u) {
    for (auto p : adj[u]) {
        int v = p.first;
        if (col[v] >= 0) continue;
        col[v] = col[u] ^ 1, dfs(v);
    }
}


int main() {
    scanf("%d %d", &n, &m);
    while (m --) {
        int u, v, b;
        scanf("%d %d %d", &u, &v, &b);
        adj[u].emplace_back(v, 1);
        adj[v].emplace_back(u, b ? -1 : 1);
    }
    memset(col, -1, sizeof col);
    col[1] = 0, dfs(1);
    for (int i = 1; i <= n; i ++) {
        for (auto p : adj[i]) {
            if (col[p.first] == col[i]) {
                puts("NO");
                return 0;
            }
        }
    }

    int ans = -inf, id = 0;
    for (int i = 1; i <= n; i ++) {
        if (!solve(i)) continue;
        int upd = *max_element(d + 1, d + n + 1) - *min_element(d + 1, d + n + 1);
        if (ans < upd) id = i, ans = upd;
    }
    if (id) {
        puts("YES");
        solve(id);
        int mn = *min_element(d + 1, d + n + 1);
        for (int i = 1; i <= n; i ++) d[i] -= mn;
        printf("%d\n", ans);
        for (int i = 1; i <= n; i ++) printf("%d ", d[i]); puts("");
    }
    else puts("NO");

    return 0;
}