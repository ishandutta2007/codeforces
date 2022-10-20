#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 5005;
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

int n, a[MAXN], cnt[MAXN], dp[MAXN];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    dp[0] = 0;
    for (int i = 1; i <= n + 1; ++i) {
        dp[i] = -INF;
        int mx = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (((i - j) & 1) &&
                (mx <= (i - j - 1) / 2) &&
                (a[i] == a[j] || j == 0 || i == n + 1)) {
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ++cnt[a[j]];
            mx = max(mx, cnt[a[j]]);
        }
        for (int j = 0; j < i; ++j) {
            cnt[a[j]] = 0;
        }
    }
    printf("%d\n", dp[n + 1] - 1);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}