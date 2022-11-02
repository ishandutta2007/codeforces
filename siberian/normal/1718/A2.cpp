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

const int N = 1e5 + 10;

int n;
int a[N];
// int dp[2][N];

// void mySwap() {
//     for (int i = 0; i < N; ++i) {
//         dp[0][i] = dp[1][i];
//         dp[1][i] = n;
//     }
// }

int dp[N];
int pref[N];

int getPref(int l, int r) {
    return pref[r] ^ pref[l - 1];
}

void solve() {
    cin >> n;
    pref[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i + 1] = a[i];
        pref[i + 1] ^= pref[i];
    }
    fill(dp, dp + n + 1, n);
    dp[0] = 0;
    int min_val = n;
    map<int, int> min_val2;
    min_val2[0] = 0 - 1;

    for (int r = 1; r <= n; ++r) {
        chkmin(min_val, dp[r - 1] - r);
        chkmin(dp[r], min_val + r + 1);

        if (min_val2.count(pref[r])) {
            chkmin(dp[r], min_val2[pref[r]] + r);
            chkmin(min_val2[pref[r]], dp[r] - (r + 1));
        } else {
            min_val2[pref[r]] = dp[r] - (r + 1);
        }

        // for (int l = 1; l <= r; ++l) {
        //     if (pref[r] == pref[l - 1]) {
        //         chkmin(dp[r], dp[l - 1] + (r - l));
        //     }
        // }
    }
    int ans = dp[n];
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