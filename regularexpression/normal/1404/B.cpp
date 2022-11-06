#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector<int> g[N];
int d[N];

void dfs(int v, int p = -1) {
    for (auto u : g[v]) {
        if (u != p) {
            d[u] = d[v] + 1;
            dfs(u, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        a--;
        b--;
        for (int i = 0; i < n; i++) g[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int v, u;
            cin >> v >> u;
            v--;
            u--;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        d[a] = 0;
        dfs(a);
        if (d[b] <= da || 2 * da >= db) {
            cout << "Alice\n";
            continue;
        }
        int st = max_element(d, d + n) - d;
        d[st] = 0;
        dfs(st);
        int mx = *max_element(d, d + n);
        cout << (mx <= 2 * da ? "Alice\n" : "Bob\n");
    }
    return 0;
}