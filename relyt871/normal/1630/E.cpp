#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 1000006;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '0') flag = -1;
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

int fac[MAXN], finv[MAXN];
int n, cnt[MAXN], m, cnts[MAXN], G;
int f[MAXN], g[MAXN];

void prework() {
    n = 1000000;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = Mul(fac[i - 1], i);
    }
    finv[n] = Inv(fac[n]);
    for (int i = n; i >= 1; --i) {
        finv[i - 1] = Mul(finv[i], i);
    }
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        cnt[i] = f[i] = g[i] = 0;
    }
    for (int i = 1, a; i <= n; ++i) {
        read(a);
        ++cnt[a];
    }
    m = G = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i]) {
            cnts[++m] = cnt[i];
            G = __gcd(G, cnt[i]);
        }
    }
    if (G == n) {
        printf("1\n");
        return;
    }
    for (int i = 1; i <= G; ++i) {
        if (G % i) continue;
        int dn = 1, pre = 0, sum = 0;
        for (int j = 1; j <= m; ++j) {
            int x = cnts[j];
            dn = Mul(dn, finv[x / i]);
            Inc(sum, Mul(pre, x / i * 2));
            Inc(pre, x / i);
        }
        f[i] = Mul(fac[n / i], dn);
        g[i] = Mul(Mul(fac[n / i - 2], dn), Mul(sum, n));
    }
    int up = 0, dn = 0;
    for (int i = 1; i <= n; ++i) {
        int j = n / __gcd(n, i);
        if (G % j) continue;
        Inc(up, g[j]);
        Inc(dn, f[j]);
    }
    printf("%d\n", Mul(up, Inv(dn)));
}

int main() {
    prework();
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}