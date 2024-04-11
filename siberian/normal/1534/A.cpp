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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m, '.'));
    for (auto& i : a) {
        for (auto& j : i) {
            cin >> j;
        }
    }
    set<char> odd, even;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if ((x + y) % 2 == 1) {
                odd.insert(a[x][y]);
            } else{
                even.insert(a[x][y]);
            }
        }
    }
    odd.erase('.');
    even.erase('.');
    if (odd.size() == 2 || even.size() == 2) {
        cout << "NO\n";
        return;
    }
    if (odd.empty() && even.empty()) {
        odd.insert('R');
        even.insert('W');
    } else if (odd.empty()) {
        odd.insert((*even.begin()) ^ 'R' ^ 'W');
    } else if (even.empty()) {
        even.insert((*odd.begin()) ^ 'R' ^ 'W');
    } else {
        if (*even.begin() == *odd.begin()) {
            cout << "NO\n";
            return;
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if ((x + y) % 2 == 1) {
                a[x][y] = *odd.begin();
            } else{
                a[x][y] = *even.begin();
            }
        }
    }
    cout << "YES\n";
    for(auto i : a) {
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