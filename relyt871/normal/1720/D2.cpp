#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 300005;

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

int n, ans;
int tot, root, ch[2][MAXN * 35], dp[2][MAXN * 35];

void solve() {
    for (int i = 1; i <= tot; ++i) {
        ch[0][i] = ch[1][i] = dp[0][i] = dp[1][i] = 0;
    }
    tot = root = ans = 1;
    read(n);
    for (int i = 0, a; i < n; ++i) {
        read(a);
        int x = (a ^ i);
        int cur = 0, p = root;
        for (int j = 29; j >= 0; --j) {
            if (!p) break;
            int q = ch[((x >> j) & 1) ^ 1][p];
            if (q) {
                cmax(cur, dp[((a >> j) & 1) ^ 1][q]);
            }
            p = ch[(x >> j) & 1][p];
        }
        ans = max(ans, ++cur);
        p = root;
        for (int j = 29; j >= 0; --j) {
            int q = ch[(x >> j) & 1][p];
            if (!q) {
                q = ch[(x >> j) & 1][p] = ++tot;
            }
            cmax(dp[(i >> j) & 1][q], cur);
            p = q;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}