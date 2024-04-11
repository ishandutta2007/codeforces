#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizoef(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int N = 105;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

int n, a[N], vis[N], dp[N][N];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        mset(vis, 0);
        for (int j = i; j <= n; ++j) {
            if (a[j] <= 100) {
                vis[a[j]] = 1;
            }
            int mex = 0;
            for (int k = 0; k <= 100; ++k) {
                if (!vis[k]) {
                    mex = k;
                    break;
                }
            }
            dp[i][j] = mex + 1;
        }
    }
    for (int len = 2; len <= n; ++len) {
        for (int l = 1, r = l + len - 1; r <= n; ++l, ++r) {
            for (int m = l; m < r; ++m) {
                dp[l][r] = max(dp[l][r], dp[l][m] + dp[m + 1][r]);
            }
        }
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ans += dp[i][j];
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}