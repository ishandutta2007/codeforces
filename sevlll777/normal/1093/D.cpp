#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fro for
#define pb push_back
#define ld long double
const int M = 998244353;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    vector<int> pows = {1};
    for (int i = 0; i < 3e5 + 228; i++) {
        pows.pb((2 * pows.back()) % M);
    }
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> gr(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            gr[a].pb(b);
            gr[b].pb(a);
        }
        bitset<400000> used;
        deque<int> q;
        vector<int> color(n);
        vector<pair<int, int>> lol;
        bool can = true;
        for (int v = 0; v < n; v++) {
            if (!used[v]) {
                q = {v};
                used[v] = true;
                color[v] = 1;
                int c1 = 1, c2 = 0;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop_front();
                    for (auto uu : gr[u]) {
                        if (!used[uu]) {
                            used[uu] = true;
                            q.pb(uu);
                            color[uu] = 3 - color[u];
                            if (color[uu] == 1) {
                                c1++;
                            } else {
                                c2++;
                            }
                        } else if (color[uu] != 3 - color[u]) {
                            can = false;
                            break;
                        }
                    }
                }
                lol.pb({c1, c2});
            }
        }
        if (can) {
            int ans = 1;
            for (auto p : lol) {
                ans *= ((pows[p.first] + pows[p.second]) % M);
                ans %= M;
            }
            cout << ans << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}