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

const int N = 8192;

int n;
int a[N];
int dp[2][N];

void mySwap() {
    for (int i = 0; i < N; ++i) {
        dp[0][i] = dp[1][i];
        dp[1][i] = n;
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int val = 0; val < N; ++val) {
        dp[1][val] = 1;
        if (val == a[0]) {
            dp[1][val] = 0;
        }
    }
    mySwap();
    for (int pos = 1; pos < n; ++pos) {
        for (int prev_val = 0; prev_val < N; ++prev_val) {
            chkmin(dp[1][a[pos] ^ prev_val], dp[0][prev_val] + 1);
        }
        for (int my_val = 0; my_val < N; ++my_val) {
            chkmin(dp[1][my_val], dp[0][0] + 1);
        }
        chkmin(dp[1][a[pos]], dp[0][0]);
        mySwap();
    }
    int ans = dp[0][0];
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