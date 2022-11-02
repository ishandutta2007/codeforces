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

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD) return a - MOD;
    return a;
}

const int N = 1111;
int dp[N][N][2];

int n;

int f(int pos, int k, int dir) {
    // cerr << "pos = " << pos << " k = " << k << " dir = " << dir << endl;
    if (dp[pos][k][dir] != -1) return dp[pos][k][dir];
    if (k == 0) return dp[pos][k][dir] = 1;
    if (dir == 0) {
        int ans = 0;
        if (pos + 1 < n) ans = add(ans, f(pos + 1, k, 0));
        else ans = add(ans, 1);
        if (pos > 0) ans = add(ans, f(pos - 1, k - 1, 1));
        else ans = add(ans, 1);
        return dp[pos][k][dir] = ans;
    } else {
        int ans = 0;
        if (pos > 0) ans = add(ans, f(pos - 1, k, 1));
        else ans = add(ans, 1);
        if (pos + 1 < n) ans = add(ans, f(pos + 1, k - 1, 0));
        else ans = add(ans, 1);
        return dp[pos][k][dir] = ans; 
    }
}

void solve() {
    int k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int dir = 0; dir < 2; ++dir) {
                dp[i][j][dir] = -1;
            }
        }
    }
    cout << f(0, k - 1, 0) << '\n';
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < k; ++j) {
    //         for (int dir = 0; dir < 2; ++dir) {
    //             if (dp[i][j][dir] != -1) {
    //                 cout << "pos = " << i << " k = " << j << " dir = " << dir << " dp = " << dp[i][j][dir] << endl;
    //             }
    //         }        
    //     } 
    // }
    // exit(0);
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