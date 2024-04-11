#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        vector<bool> row(n, false), col(n, false);
        vector<int> cnt(2 * n);
        set<pair<int, int>> oke;
        int lad = 0;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            if (a != b) {
                row[a] = true;
                col[b] = true;
                lad++;
                oke.insert({a, b});
            }
        }
        vector<vector<int>> g(n);
        for (auto pep : oke) {
            g[pep.first].pb(pep.second);
            g[pep.second].pb(pep.first);
        }
        vector<bool> used(n);
        for (int v = 0; v < n; v++) {
            if (!used[v] && (!row[v] || !col[v])) {
                used[v] = true;
                vector<int> st = {v};
                while (!st.empty()) {
                    int u = st.back();
                    st.pop_back();
                    for (auto uu : g[u]) {
                        if (!used[uu]) {
                            used[uu] = true;
                            st.pb(uu);
                        }
                    }
                }
            }
        }
        for (int v = 0; v < n; v++) {
            if (!g[v].empty() && !used[v]) {
                lad++;
                used[v] = true;
                vector<int> st = {v};
                while (!st.empty()) {
                    int u = st.back();
                    st.pop_back();
                    for (auto uu : g[u]) {
                        if (!used[uu]) {
                            used[uu] = true;
                            st.pb(uu);
                        }
                    }
                }
            }
        }
        cout << lad;
        cout << '\n';
    }
}