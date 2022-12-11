#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

bool fail;

void dfs(int v, int cl, vector<int> &col, const vector<vector<pair<int, int>>> &es) {
    if (col[v] != -1) {
        if (col[v] != cl) fail = true;
        return;
    }
    col[v] = cl;
    for (const auto &[w, e] : es[v]) {
        dfs(w, (cl + e) % 2, col, es);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    vector<vector<int>> a(n);
    for (int i = 0; i < m; i++) {
        int k, x;
        cin >> k;
        while (k--) {
            cin >> x;
            a[x - 1].push_back(i);
        }
    }

    vector<vector<pair<int, int>>> es(m);

    for (int i = 0; i < n; i++) {
        int v1 = a[i][0];
        int v2 = a[i][1];
        es[v1].emplace_back(v2, 1 - r[i]);
        es[v2].emplace_back(v1, 1 - r[i]);
    }

    vector<int> col(m, -1);
    fail = false;
    for (int i = 0; i < m; i++) {
        if (col[i] == -1) dfs(i, 0, col, es);
    }
    cout << (fail ? "NO\n" : "YES\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 3;
    for (int i = 1; i < T; i++) solve();    
#endif
}