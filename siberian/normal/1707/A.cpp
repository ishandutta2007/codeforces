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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vin(a);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] <= q) {
            ans[i] = 1;
        }
    }

    auto check = [&] (int len) -> bool {
        int cur_q = q;
        for (int i = n - len; i < n && cur_q > 0; ++i) {
            if (a[i] <= cur_q) {

            } else {
                --cur_q;
            }
            --len;
        }
        return len == 0;
    };

    int L = 0, R = n + 1;
    while (L < R - 1) {
        int M = (L + R) / 2;
        if (check(M)) {
            L = M;
        } else {
            R = M;
        }
    }

    for (int i = n - L; i < n; ++i) {
        ans[i] = 1;
    }

    int sum = 0;

    for (auto i : ans) {
        cout << i;
        // sum += i;
    }
    cout << '\n';
    // cout << sum << endl;

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