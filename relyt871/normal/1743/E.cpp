#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 5005;

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

int p1, p2, h, s;
LL t1, t2, f[N], g[N], dp[N];

void solve() {
    read(p1); read(t1);
    read(p2); read(t2);
    if (t1 > t2) {
        swap(p1, p2);
        swap(t1, t2);
    }
    read(h); read(s);
    for (int i = 1; i <= h; ++i) {
        f[i] = g[i] = dp[i] = 1e18;
    }
    LL ans = 1e18;
    for (int i = 1; i <= h; ++i) {
        LL tot = t2 * i;
        LL dmg = (i - 1) * (p2 - s) + (tot / t1 - 1) * (p1 - s) + (p1 + p2 - s);
        if (dmg > h) {
            ans = min(ans, tot);
            break;
        }
        f[dmg] = min(f[dmg], tot);
        if (tot % t1) {
            LL tot2 = (tot / t1 + 1) * t1;
            dmg += (p1 - s);
            if (dmg <= h) {
                f[dmg] = min(f[dmg], tot2);
            } else {
                ans = min(ans, tot2);
            }
        }
    }
    for (int i = h - 1; i >= 0; --i) {
        g[i] = min(g[i + 1], f[i]);
    }
    for (int i = 0; i <= h; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j] + f[j]);
        }
        LL cur = dp[i];
        LL nxt1 = cur + t1, nxt2 = cur + t2;
        int rem = h - i;
        ans = min(ans, dp[i] + g[rem]);
        while (rem > 0) {
            if (nxt1 < nxt2) {
                cur = nxt1;
                nxt1 += t1;
                rem -= (p1 - s);
            } else {
                cur = nxt2;
                nxt2 += t2;
                rem -= (p2 - s);
            }
        }
        ans = min(ans, cur);
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}