#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1005;
const int MAXK = 25;

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

int n, k, c[MAXN][MAXK], v[MAXN], w[MAXN];

void solve() {
    read(n); read(k);
    for (int i = 1; i <= n; ++i) {
        int x = 0;
        for (int j = 0; j < k; ++j) {
            read(c[i][j]);
            x = x * 3 + c[i][j];
        }
        v[i] = w[i] = x;
    }
    sort(w + 1, w + n + 1);
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            int x = 0;
            for (int t = 0; t < k; ++t) {
                int d = 0;
                if (c[i][t] == c[j][t]) {
                    d = c[i][t];
                } else {
                    while (d == c[i][t] || d == c[j][t]) {
                        ++d;
                    }
                }
                x = x * 3 + d;
            }
            int pos = lower_bound(w + 1, w + n + 1, x) - w;
            if (w[pos] == x) {
                ++cnt;
            }
        }
        cnt /= 2;
        ans += cnt * (cnt - 1) / 2;
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}