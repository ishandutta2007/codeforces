#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 200005;
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

char s[MAXN];
int n, a[MAXN], dp[MAXN][2];

void solve() {
    read(n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    dp[1][0] = dp[1][1] = -INF;
    if (s[1] - '0') {
        dp[1][1] = a[1];
    } else {
        dp[1][0] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        if (s[i] - '0') {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
            dp[i][0] = dp[i - 1][0] + a[i - 1];
        } else {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = -INF;
        }
    }
    printf("%d\n", max(dp[n][0], dp[n][1]));
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}