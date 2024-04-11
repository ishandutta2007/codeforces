#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 300005;
const int N = 20;
const int MAXS = (1 << 16) + 5;

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

namespace ModCalculator {
    const int MOD = 998244353;
    inline void Inc(int &x, int y) {
        x += y; if (x >= MOD) x -= MOD;
    }
    inline void Dec(int &x, int y) {
        x -= y; if (x < 0) x += MOD;
    }
    inline int Add(int x, int y) {
        Inc(x, y); return x;
    }
    inline int Sub(int x, int y) {
        Dec(x, y); return x;
    }
    inline int Mul(int x, int y) {
        return 1LL * x * y % MOD;
    }
    inline int Ksm(int x, int y) {
        int ret = 1;
        for (; y; y >>= 1) {
            if (y & 1) ret = Mul(ret, x);
            x = Mul(x, x);
        }
        return ret;
    }
    inline int Inv(int x) {
        return Ksm(x, MOD - 2);
    }
}
using namespace ModCalculator;

int d, n, m, q, lan[MAXN], pos[MAXN];
int seg[N][N], f[MAXS], perm[N], dis[N];

inline bool dis_cmp(int x, int y) {
    return (dis[x] < dis[y]);
}

void solve() {
    read(d); read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        read(lan[i]);
    }
    sort(lan + 1, lan + n + 1);
    for (int i = 1; i <= m; ++i) {
        read(pos[i]);
    }
    sort(pos + 1, pos + m + 1);
    pos[0] = -1;
    pos[m + 1] = d + 1;

    for (int i = 0; i <= m; ++i) {
        for (int j = i + 1; j <= m + 1; ++j) {
            int l = 1, r = n, way = 1;
            while (lan[l] < pos[i]) ++l;
            while (lan[r] > pos[j]) --r;
            for (int k = l; k <= r; ++k) {
                int a = (i == 0? d + 1 : lan[k] - pos[i]);
                int b = (j == m + 1? d + 1 : pos[j] - lan[k]);
                way = Mul(way, min(a, b));
            }
            seg[i][j] = way;
        }
    }
    int S = (1 << m);
    for (int s = 0; s < S; ++s) {
        int lst = 0, way = 1;
        for (int i = 1; i <= m; ++i) {
            if ((s >> (i - 1)) & 1) {
                way = Mul(way, seg[lst][i]);
                lst = i;
            }
        }
        f[s] = Mul(way, seg[lst][m + 1]);
    }
    for (int s = S - 1; s >= 0; --s) {
        int T = S - 1 - s;
        for (int t = T; t; t = (t - 1) & T) {
            Dec(f[s], f[s | t]);
        }
    }
    for (int i = 1; i < S; i <<= 1) {
        for (int j = 0; j < S; j += (i << 1)) {
            for (int k = 0; k < i; ++k) {
                Inc(f[i + j + k], f[j + k]);
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        perm[i] = i;
    }
    read(q);
    while (q--) {
        int x; read(x);
        for (int i = 1; i <= m; ++i) {
            dis[i] = abs(pos[i] - x);
        }
        sort(perm + 1, perm + m + 1, dis_cmp);
        int cov = 0, ans = 0;
        for (int i = 1; i <= m; ++i) {
            Inc(ans, Mul(dis[perm[i]] - dis[perm[i - 1]], f[cov]));
            cov |= (1 << (perm[i] - 1));
        }
        Inc(ans, Mul(d - dis[perm[m]] + 1, f[cov]));
        printf("%d\n", ans);
    }
}

int main() {
    solve();
    return 0;
}