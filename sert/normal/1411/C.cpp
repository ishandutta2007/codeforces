#include <bits/stdc++.h>
using namespace std;

bool D = false;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n), sz(n, 1), x(n), y(n);
    iota(p.begin(), p.end(), 0);
    function<int(int)> fnd = [&p, &fnd](int x) -> int { return p[x] == x ? x : p[x] = fnd(p[x]); };
    auto uniq = [&](int v1, int v2) { sz[fnd(v2)] += sz[fnd(v1)]; p[fnd(v1)] = fnd(v2); };

    vector<int> h(n + 2, -1), v(n + 2, -1);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        if (h[y[i]] != -1) uniq(i, h[y[i]]);
        if (v[x[i]] != -1) uniq(i, v[x[i]]);
        h[x[i]] = i;
        v[y[i]] = i;
        if (x[i] != y[i])
            ans++;
    }
    vector<set<int>> range(n);
    for (int i = 0; i < m; i++) {
        range[fnd(i)].insert(x[i] + 1);
        range[fnd(i)].insert(-y[i]);
    }

    for (int i = 0; i < m; i++)
        if (fnd(i) == i && static_cast<int>(range[i].size()) == sz[i])
            ans++;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
#ifdef SERT
    freopen("../a.in", "r", stdin);
    D = true;
#endif
    cin >> t;
    while (t--)
        solve();
}