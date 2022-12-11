#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#ifdef SERT
bool D = true;
#else
bool D = false;
#endif

void dfs(int v, int fn, const vector<vector<int>> &es, vector<int> &pr, vector<bool> &u) {
    if (u[v]) return;
    u[v] = true;
    for (int w : es[v]) {
        if (!u[w]) pr[w] = v;
        dfs(w, fn, es, pr, u);
    }
}

struct dsu_t {
    vector<int> pr;
    explicit dsu_t(int sz = 0) {
        pr.resize(sz);
        for (int i = 0; i < sz; i++)
            pr[i] = i;
    }
    int fnd(int v) { return (v == pr[v] ? v : pr[v] = fnd(pr[v])); }
    bool uniq(int v1, int v2) { v1 = fnd(v1); v2 = fnd(v2); if (v1 == v2) return false; pr[v1] = v2; return true; }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> es(n);
    dsu_t dsu(n);
    while (m--) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        if (dsu.uniq(v1, v2)) {
            //cout << "add " << v1 << " " << v2 << endl;
            es[v1].push_back(v2);
            es[v2].push_back(v1);
        }
    }

    int q;
    cin >> q;
    vector<int> deg(n, 0);
    vector<pair<int, int>> e;
    while (q--) {
        int v1, v2;
        cin >> v1 >> v2;
        deg[v1 - 1]++;
        deg[v2 - 1]++;
        e.emplace_back(v1 - 1, v2 - 1);
    }
    int numOdd = 0;
    for (int i = 0; i < n; i++)
        numOdd += deg[i] % 2;

    if (numOdd) {
        cout << "NO\n" << numOdd / 2 << "\n";
        return;
    }

    cout << "YES\n";
    for (const auto &[v1, v2] : e) {
        vector<int> pr(n, -1);
        vector<bool> u(n, false);
        dfs(v1, v2, es, pr, u);
        vector<int> path = {v2};
        while (path.back() != v1) {
            path.push_back(pr[path.back()]);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (int x : path)
            cout << x + 1 << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    if (D) {
        freopen("../a.in", "r", stdin);
        t += 1;
    }
    //cin >> t;
    while (t--) {
        solve();
    }
}