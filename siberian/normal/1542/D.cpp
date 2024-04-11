#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

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

int sub(int a, int b) {
    a -= b;
    if (a < 0) return a + MOD;
    return a;
}

int mul(int a, int b) {
    return (ll)a * b % MOD;
}

const int N = 510;
int n;
char c[N];
int a[N];

int dp[N][N];

int solve(int pos) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int cnt = 0; cnt <= i; ++cnt) {
            if (dp[i][cnt] == 0) continue;
            if (i != pos) {
                dp[i + 1][cnt] = add(dp[i + 1][cnt], dp[i][cnt]);
            }
            if (c[i] == '+') {
                if (i < pos) {
                    int nxtCnt = (a[i] <= a[pos] ? 1 : 0) + cnt;
                    dp[i + 1][nxtCnt] = add(dp[i + 1][nxtCnt], dp[i][cnt]);
                } else if (i == pos) {
                    dp[i + 1][cnt] = add(dp[i + 1][cnt], dp[i][cnt]);
                } else {
                    int nxtCnt = (a[i] < a[pos] ? 1 : 0) + cnt;
                    dp[i + 1][nxtCnt] = add(dp[i + 1][nxtCnt], dp[i][cnt]);    
                }  
            } else if (c[i] == '-') {
                if (i < pos) {
                    int nxtCnt = max(0, cnt - 1);
                    dp[i + 1][nxtCnt] = add(dp[i + 1][nxtCnt], dp[i][cnt]);
                } else if (i == pos) {
                    assert(false);
                } else {
                    int nxtCnt = cnt - 1;
                    if (nxtCnt >= 0) {
                        dp[i + 1][nxtCnt] = add(dp[i + 1][nxtCnt], dp[i][cnt]);
                    }
                }  
            } else {
                assert(false);
            }
        }
    }
    // cerr << "dp = " << endl;
    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j <= n; ++j) {
    //         cerr << dp[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    int ans = 0;
    for (int cnt = 0; cnt <= n; ++cnt) {
        ans = add(ans, dp[n][cnt]);
    }
    // cerr << "pos = " << pos << " cnt = " << ans << endl;
    ans = mul(ans, a[pos] % MOD);
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (c[i] == '+') {
            cin >> a[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] == '+') {
            int fans = solve(i);
            // cerr << "i = " << i << " fans = " << fans << endl;
            ans = add(ans, fans);
            // ans = add(ans, solve(i));
        }
    }
    cout << ans << endl;
    return 0;
}