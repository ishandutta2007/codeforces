#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizoef(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int N = 105;
const LL INF = 0x3f3f3f3f3f3f3f3f;

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

inline void cmin(LL &x, LL y) {
    if (x > y) x = y;
}

int n, a[N], b[N];
LL dp[N][N * N];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
    }
    int lim = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        int lim2 = lim + max(a[i], b[i]);
        for (int j = 0; j <= lim2; ++j) {
            dp[i][j] = INF;
        }
        for (int j = 0; j <= lim; ++j) {
            cmin(dp[i][j + a[i]], dp[i - 1][j] + a[i] * j + b[i] * (sum - j));
            cmin(dp[i][j + b[i]], dp[i - 1][j] + b[i] * j + a[i] * (sum - j));
            //cerr << dp[i][j + a[i]] << " " << dp[i][j + b[i]] << endl;
        }
        lim = lim2;
        sum += a[i] + b[i];
    }
    LL ans = INF;
    for (int i = 0; i <= lim; ++i) {
        cmin(ans, dp[n][i]);
    }
    ans *= 2;
    for (int i = 1; i <= n; ++i) {
        ans += (n - 1) * (a[i] * a[i] + b[i] * b[i]);
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