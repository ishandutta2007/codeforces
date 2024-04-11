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
    auto check = [&] (int cnt) -> bool {
        vector<bool> used(n, false);
        {
            int cnt1 = 0;
            int pos = 0;
            while (pos < n && cnt1 < cnt) {
                if (a[pos] == 1) {
                    used[pos] = true;
                    ++cnt1;
                }
                ++pos;
            }
        }
        {
            int cnt0 = 0;
            int pos = n - 1;
            while (pos >= 0 && cnt0 < cnt) {
                if (a[pos] == 0) {
                    used[pos] = true;
                    ++cnt0;
                }
                --pos;
            }
        }
        vector<int> has;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                has.push_back(a[i]);
            }
        }
        for (int i = 1; i < (int)has.size(); ++i) {
            if (has[i] < has[i - 1]) {
                return false;
            }
        }
        return true;
    };
    int L = -1;
    int R = n + 1;
    while (L < R - 1) {
        int M = (L + R) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << R << '\n';
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