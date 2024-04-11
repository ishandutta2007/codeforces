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
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(5, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < 5; ++j) {
            cnt += a[ans][j] < a[i][j];
        }
        if (cnt < 3) {
            ans = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == ans) continue;
        int cnt = 0;
        for (int j = 0; j < 5; ++j) {
            cnt += a[ans][j] < a[i][j];
        }
        if (cnt < 3) {
            cout << "-1\n";
            return;
        }
    }

    cout << ans + 1 << '\n';
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