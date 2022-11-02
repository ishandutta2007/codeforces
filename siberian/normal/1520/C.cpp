#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i % 2; j < n; j += 2) {
            a[i][j] = ++ptr;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1 - i % 2; j < n; j += 2) {
            a[i][j] = ++ptr;
        }
    }
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int it = 0; it < 4; ++it) {
                int x = i + dx[it];
                int y = j + dy[it];
                if (x < 0 || x >= n || y < 0 || y >= n) continue;
                if (abs(a[i][j] - a[x][y]) == 1) {
                    cout << "-1\n";
                    return;
                }
            }
        }
    }
    for (auto i : a) {
        for (auto j : i) {
            cout << j << ' ';
        }   
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}