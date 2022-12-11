        #include <bits/stdc++.h>
        using namespace std;
         
        using ll = long long;
        #ifdef SERT
        bool D = true;
        #else
        bool D = false;
        #endif
         
        void solve() {
            int n, m;
            cin >> n >> m;
            vector<string> s(n);
            for (auto &x : s) {
                cin >> x;
            }
         
            vector<int> nx(m + 1, -1);
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m - 1; j++) {
                    if (s[i + 1][j] == 'X' && s[i][j + 1] == 'X')
                        nx[j] = j;
                }
            }
         
            nx[m] = m + 1;
            for (int j = m - 1; j >= 0; j--)
                if (nx[j] == -1)
                    nx[j] = nx[j + 1];
         
            int q;
            cin >> q;
            while (q--) {
                int l, r;
                cin >> l >> r;
                l--;
                r--;
                cout << (l == r || nx[l] >= r ? "YES\n" : "NO\n");
            }
        }
         
        int main() {
            int t = 1;
            if (D) {
                freopen("../a.in", "r", stdin);
            }
            //cin >> t;
            while (t--) {
                solve();
            }
        }