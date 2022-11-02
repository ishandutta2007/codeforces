#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m, '0'));
    vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
    vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            bool ok = true;
            for (int it = 0; it < 8; ++it) {
                int nx = x + dx[it];
                int ny = y + dy[it];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (a[nx][ny] == '1') {
                    ok = false;
                }
            }
            if (x != 0 && x != n - 1 && y != 0 && y != m - 1) continue;
            if (!ok) continue;
            a[x][y] = '1';
        }
    }
    for (auto i : a) {
        for (auto j : i) {
            cout << j;
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