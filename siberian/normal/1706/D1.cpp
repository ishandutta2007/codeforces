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

const int C = 3001;

bool used[C];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vin(a);
    fill(used, used + C, 0);
    for (auto val : a) {
        for (int p = 1; p <= k; ++p) {
            used[val / p] = true;
        } 
    }
    int ans = INT_MAX;
    for (int max_val = 0; max_val < C; ++max_val) {
        if (!used[max_val]) {
            continue;
        }
        // cerr << "max_val = " << max_val << endl;
        int min_val = max_val;
        for (auto val : a) {
            int L = 0, R = k + 1;
            while (L < R - 1) {
                int M = (L + R) / 2;
                if (val / M <= max_val) {
                    R = M;
                } else {
                    L = M;
                }
            }
            if (R == k + 1) {
                min_val = INT_MAX;
                break;
            }
            chkmin(min_val, val / R);
        }
        // cerr << "min_val = " << min_val << endl;
        if (min_val != INT_MAX) {
            chkmin(ans, max_val - min_val);
        }
    }
    cout << ans << '\n';
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