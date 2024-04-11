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

#define int ll

int calc(const vector<int>& a) {
    vector<int> pref = a;
    for (int i = 1; i < (int)pref.size(); ++i) {
        pref[i] += pref[i - 1];
    }
    int ans = 0;
    for (auto i : pref) {
        ans += i;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    int max_val = LONG_LONG_MIN;
    int min_val = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        vin(a[i]);
        int val = calc(a[i]);
        chkmax(max_val, val);
        chkmin(min_val, val);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (calc(a[i]) == min_val) {
            cout << i + 1 << " " << max_val - min_val << '\n';
            // cout.flush();
            ++cnt;
        }
    }
    assert(cnt == 1);
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