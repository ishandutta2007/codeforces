#include <bits/stdc++.h>

using namespace std;

int n, k, ans;
vector < vector < int > > g;
vector < int > ve;

void dfs(int v, int p, int c = 0) {
    if (c > k) {
        return;
    }
    ans += g[v].size() == 1 && v != 1;
    for (int i = 0; i < (int)g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
        dfs(to, v, ve[to] == 1 ? c + 1 : 0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    ve.resize(n + 1);
    g.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> ve[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, -1, ve[1] == 1);
    cout << ans << endl;
    return 0;
}