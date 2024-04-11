#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        vector<int> ans;
        vector<bool> used(n, false);
        ans.pb(0);
        used[0] = true;
        set<int> cheli;
        for (auto v : g[0]) {
            used[v] = true;
            cheli.insert(v);
        }
        int cnt = 0;
        while (!cheli.empty()) {
            cnt++;
            int gg = *cheli.begin();
            cheli.erase(gg);
            for (auto uu : g[gg]) {
                if (!used[uu]) {
                    ans.pb(uu);
                    used[uu] = true;
                    for (auto www : g[uu]) {
                        if (!used[www]) {
                            cheli.insert(www);
                            used[www] = true;
                        }
                    }
                }
            }
        }
        if (cnt+ans.size() == n) {
            cout << "YES\n";
            cout << ans.size() << '\n';
            for (auto x : ans) cout << x + 1 << ' ';
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}