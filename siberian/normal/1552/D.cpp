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
    vector<int> a(n);
    vin(a);
    int pw = 1;
    for (int i = 0; i < n; ++i) {
        pw *= 3;
    }
    for (int mask = 1; mask < pw; ++mask) {
        int ans = 0;
        int fmask = mask;
        for (int i = 0; i < n; ++i) {
            if (fmask % 3 == 1) {
                ans += a[i];
            } else if (fmask % 3 == 2) {
                ans -= a[i];
            }
            fmask /= 3;
        }
        if (ans == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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