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

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        vin(a);
        int ans = 0;
        for (int l = 0; l < n; ) {
            int r = l;
            int min_val = a[l];
            int max_val = a[l];
            while (r < n && (max_val - min_val + 1) / 2 <= x) {
                ++r;
                if (r < n) {
                    chkmin(min_val, a[r]);
                    chkmax(max_val, a[r]);
                }
            }
            if (l != 0) {
                ++ans;
            }
            l = r;
        }
        cout << ans << '\n';
    }
    return 0;
}