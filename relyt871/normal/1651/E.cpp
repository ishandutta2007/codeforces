#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 3005;
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

inline void cmin(int &x, int y) {
    if (x > y) x = y;
}
inline void cmax(int &x, int y) {
    if (x < y) x = y;
}

int n, vis[MAXN];
int g[MAXN][2];

inline int other(int u, int v) {
    return (g[u][0] == v)? g[u][1] : g[u][0];
}

inline int extend(int l, int r, int t) {
    if (l <= t && t <= r) return 0;
    if (t < l) {
        return (n - r + 1) * (l - t);
    } else {
        return (t - r) * l;
    }
}

inline int extend2(int l, int r, int t1, int t2) {
    if (l <= t1 && t1 <= r) return 0;
    if (l <= t2 && t2 <= r) return 0;
    if (t1 > t2) swap(t1, t2);
    if (t2 < l) {
        return (n - r + 1) * (l - t2);
    } else if (t1 > r) {
        return (t1 - r) * l;
    } else {
        return (t2 - r) * (l - t1);
    }
}

void solve() {
    read(n);
    for (int i = 1, u, v; i <= n + n; ++i) {
        read(u); read(v);
        (g[u][0]? g[u][1] : g[u][0]) = v;
        (g[v][0]? g[v][1] : g[v][0]) = u;
    }
    LL ans = 0;
    for (int i = 1; i <= n + n; ++i) {
        for (int j = 0; j < 2; ++j) {
            int f1 = i, f2 = g[i][j], b1 = f2, b2 = f1, len = 1;
            int l1 = f1, r1 = f1, l2 = f2, r2 = f2;
            if (i > n) {
                swap(l1, l2);
                swap(r1, r2);
            }
            while (b1 != i) {
                int t1 = other(f1, f2), t2 = other(b1, b2);
                int tmp1 = 0, tmp2 = 0;
                if (t1 <= n && t2 <= n) {
                    tmp1 = extend2(l1, r1, t1, t2);
                } else if (t1 <= n) {
                    tmp1 = extend(l1, r1, t1);
                } else if (t2 <= n) {
                    tmp1 = extend(l1, r1, t2);
                } else {
                    tmp1 = (n - r1 + 1) * l1;
                }
                if (t1 > n && t2 > n) {
                    tmp2 = extend2(l2 - n, r2 - n, t1 - n, t2 - n);
                } else if (t1 > n) {
                    tmp2 = extend(l2 - n, r2 - n, t1 - n);
                } else if (t2 > n) {
                    tmp2 = extend(l2 - n, r2 - n, t2 - n);
                } else {
                    tmp2 = (n - (r2 - n) + 1) * (l2 - n);
                }
                ans += 1LL * (len + 1) / 2 * tmp1 * tmp2;
                int tmp = other(b1, b2);
                b2 = b1;
                b1 = tmp;
                ++len;
                if (b1 <= n) {
                    cmin(l1, b1);
                    cmax(r1, b1);
                } else {
                    cmin(l2, b1);
                    cmax(r2, b1);
                }
            }
        }
    }
    ans /= 2;
    for (int i = 1; i <= n + n; ++i) {
        if (vis[i]) continue;
        vis[i] = 1;
        int b1 = g[i][0], b2 = i;
        int l1 = i, r1 = i, l2 = b1, r2 = b1, len = 1;
        while (b1 != i) {
            vis[b1] = 1;
            int tmp = other(b1, b2);
            b2 = b1;
            b1 = tmp;
            ++len;
            if (b1 <= n) {
                cmin(l1, b1);
                cmax(r1, b1);
            } else {
                cmin(l2, b1);
                cmax(r2, b1);
            }
        }
        ans += 1LL * len / 2 * (n - r1 + 1) * l1 * (n - (r2 - n) + 1) * (l2 - n);
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}