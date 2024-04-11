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

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) return a - MOD;
    return a;
} 

int mul(int a, int b) {
    return (ll)a * b % MOD;
}

const int N = 1e6 + 228;
int dp[N];
int p[N];

int cnt[N];

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    for (int i = 2; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            cnt[j]++;
        }
    }
    p[0] = 0;
    for (int n = 1; n < N; ++n) {
        dp[n] = 1;
        // for (int len = 2; len <= n; ++len) {
            // if (n % len == 0) {
                // dp[n] = add(dp[n], 1);
            // }
        // }
        dp[n] = add(dp[n], cnt[n]);
        dp[n] = add(dp[n], p[n - 1]);
        p[n] = add(dp[n], p[n - 1]);
    }
    // cerr << "dp = " << endl;
    // for (int n = 1; n < N; ++n) {
    //     cerr << "n = " << n << " dp[n] = " << dp[n] << endl;
    // }
    int x;
    cin >> x;
    cout << dp[x] << endl;
    return 0;
}