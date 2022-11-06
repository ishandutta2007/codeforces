#include<bits/stdc++.h>
using namespace std;

#define int long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()

void no() {
    cout << "NO\n";
    exit(0);
}

const int N = 2e3 + 5;

int n, d[N][N], id[N];
vector<pair<int, int>> g[N];

void addEdge(int u, int v, int w) {
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
}

void dfs(int u, int s, int h = 0, int p = -1) {
    if (d[s][u] != h) no();
    for (auto e : g[u]) {
        int v = e.x, w = e.y;
        if (v != p) dfs(v, s, h + w, u);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> d[i][j];
    }
    id[0] = -1;
    for (int it = 1; it < n; it++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (id[i] != -1 && (u == -1 || d[i][id[i]] < d[u][id[u]])) u = i;
        }
        if (d[u][id[u]] == 0) no();
        addEdge(u, id[u], d[u][id[u]]);
        id[u] = -1;
        for (int i = 0; i < n; i++) {
            if (id[i] != -1 && d[i][u] < d[i][id[i]]) id[i] = u;
        }
    }
    for (int i = 0; i < n; i++) dfs(i, i);
    cout << "YES\n";
    return 0;
}