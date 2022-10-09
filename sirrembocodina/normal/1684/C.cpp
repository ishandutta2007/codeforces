#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct my_hash {
    inline size_t operator()(const pair<int, int>& a) const {
        return a.first * 31 + a.second;
    }
};

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        bool bad = false;
        vector<int> ind_prev;
        vector<bool> bar(m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            vector<int> b = a[i];
            sort(b.begin(), b.end());
            vector<int> ind;
            for (int j = 0; j < m; j++) {
                if (b[j] != a[i][j]) {
                    ind.push_back(j);
                }
            }
            if (ind.size() > 2) {
                bad = true;
                break;
            }
            if (ind.size() == 2) {
                if (ind_prev.empty()) {
                    ind_prev = ind;
                } else if (ind_prev != ind) {
                    bad = true;
                    break;
                }
                continue;
            }
            for (int j = 0; j + 1 < m; j++) {
                if (b[j] != b[j + 1]) {
                    bar[j] = true;
                }
            }
        }
        if (bad) {
            cout << "-1\n";
            continue;
        }
        if (ind_prev.size()) {
            bool ok = true;
            for (int i = ind_prev[0]; i < ind_prev[1]; i++) {
                if (bar[i]) {
                    ok = false;
                }
            }
            if (!ok) {
                cout << "-1\n";
            } else {
                cout << ind_prev[0] + 1 << ' ' << ind_prev[1] + 1 << '\n';
            }
            continue;
        }
        cout << "1 1\n";
    }
}