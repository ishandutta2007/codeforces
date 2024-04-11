#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 505;
const int INF = 0x3f3f3f3f;

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

template <typename T> inline void cmax(T &x, T y) {
    if (x < y) x = y;
}

int n, a[N], s[N], dp[2][N][N];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        s[i] = s[i - 1] + a[i];
    }
    int pre = 0, cur = 1;
    for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= n; ++k) {
            dp[pre][j][k] = -INF;
        }
    }
    dp[pre][1][1] = a[1];
    dp[pre][2][0] = a[2];
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                dp[cur][j][k] = dp[pre][j][k] + a[j];
            }
        }
        for (int k = 0, w; k <= n; ++k) {
            int tmp = -INF;
            for (int j = 1; j <= n; ++j) {
                if (j >= i && (w = k + 1 - j + i) >= 0) {
                    cmax(dp[cur][j][w], tmp + a[j]);
                }
                cmax(tmp, dp[pre][j][k]);
            }
        }
        swap(pre, cur);
    }
    int ans = -INF;
    for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= n; ++k) {
            cmax(ans, dp[pre][j][k]);
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}