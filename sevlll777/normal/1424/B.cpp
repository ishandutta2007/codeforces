#include <bits/stdc++.h>

//#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

const int MAXN = 20500;

vector<int> g[MAXN];
int used[MAXN];
int cnt1 = 0, cnt2 = 0;

int dfs(int v, int n) {
    if (v >= n) {
        cnt2++;
    } else {
        cnt1++;
    }
    used[v] = 1;
    for (auto u : g[v]) {
        if (!used[u]) {
            dfs(u, n);
        }
    }
    return 0;
}

bool sol(int n) {
    for (int i = 0; i < n * 2; i++) {
        used[i] = 0;
    }
    for (int v = 0; v < n; v++) {
        cnt1 = cnt2 = 0;
        if (!used[v]) {
            dfs(v, n);
            if (cnt1 != cnt2) {
                return false;
            }
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edge;
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        edge.emplace_back(d, u - 1, v - 1);
    }
    sort(all(edge));
    int l = 0, r = m + 1;
    while (r - l > 1) {
        int m1 = (l + r) / 2;
        for (int i = 0; i < n * 2; i++) {
            g[i] = {};
        }
        for (int i = 0; i < m1; i++) {
            int u = get<1>(edge[i]), v = get<2>(edge[i]);
            g[u].push_back(v + n);
            g[v + n].push_back(u);
        }
        if (!sol(n)) {
            l = m1;
        } else {
            r = m1;
        }
    }
    if (r == m + 1) {
        cout << -1 << '\n';
    } else {
        cout << get<0>(edge[r - 1]) << '\n';
    }
}