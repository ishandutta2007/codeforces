#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int n;
vector<int> g[N];
int sz[N], pr[N], leaf;

void dfs(int v) {
    sz[v] = 1;
    for (auto u : g[v]) {
        if (u != pr[v]) {
            pr[u] = v;
            dfs(u);
            sz[v] += sz[u];
        }
    }
}

void find_leaf(int v) {
    if (sz[v] == 1) leaf = v;
    for (auto u : g[v]) {
        if (u != pr[v]) find_leaf(u);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) g[i].clear();
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for (int i = 0; i < n; ++i) pr[i] = -1;
        dfs(0);
        int who = -1;
        for (int i = 0; i < n; ++i) {
            if (sz[i] == n - sz[i]) who = i;
        }
        if (who == -1) cout << 1 << " " << g[0][0] + 1 << '\n' << 1 << " " << g[0][0] + 1 << '\n'; else {
            leaf = -1;
            find_leaf(who);
            cout << pr[leaf] + 1 << " " << leaf + 1 << '\n' << pr[who] + 1 << " " << leaf + 1 << '\n';
        }
    }
    return 0;
}