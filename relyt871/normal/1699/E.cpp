#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 5000006;

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

int n, m;
int vis[MAXN], cnt[MAXN], dp[MAXN];

void solve() {
    read(n); read(m);
    for (int i = 1; i <= m; ++i) {
        vis[i] = cnt[i] = 0;
        dp[i] = i;
    }
    int mn = m, mx = 0;
    for (int i = 1; i <= n; ++i) {
        int x; read(x);
        vis[x] = cnt[x] = 1;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    int ans = mx - mn;
    for (int i = sqrt(m); i > 1; --i) {
        for (int j = i * i; j <= m; j += i) {
            if (vis[j]) {
                --cnt[dp[j]];
            }
            dp[j] = min(dp[j], dp[j / i]);
            if (vis[j]) {
                ++cnt[dp[j]];
            }
        }
        while (!cnt[mx]) {
            --mx;
        }
        ans = min(ans, mx - min(mn, i));
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