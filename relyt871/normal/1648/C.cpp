#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 200005;

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

int n, m, s[MAXN], t[MAXN], cnt[MAXN];
int fac[MAXN], finv[MAXN];

struct BIT {
    int tr[MAXN];
    inline void Add(int x, int v) {
        for (; x < MAXN; x += (x & (-x))) {
            Inc(tr[x], v);
        }
    }
    inline int Sum(int x) {
        int ret = 0;
        for (; x; x -= (x & (-x))) {
            Inc(ret, tr[x]);
        }
        return ret;
    }
} bit;

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        read(s[i]);
        ++cnt[s[i]];
    }
    for (int i = 1; i <= m; ++i) {
        read(t[i]);
    }
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = Mul(fac[i - 1], i);
    }
    finv[n] = Inv(fac[n]);
    for (int i = n; i >= 1; --i) {
        finv[i - 1] = Mul(finv[i], i);
    }

    int dn = 1;
    for (int i = 1; i <= 200000; ++i) {
        if (cnt[i]) {
            dn = Mul(dn, finv[cnt[i]]);
            bit.Add(i, Mul(fac[cnt[i]], finv[cnt[i] - 1]));
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (i) {
            if (!cnt[t[i]]) {
                break;
            }
            dn = Mul(dn, fac[cnt[t[i]]]);
            bit.Add(t[i], MOD - Mul(fac[cnt[t[i]]], finv[cnt[t[i]] - 1]));
            --cnt[t[i]];
            dn = Mul(dn, finv[cnt[t[i]]]);
            if (cnt[t[i]]) {
                bit.Add(t[i], Mul(fac[cnt[t[i]]], finv[cnt[t[i]] - 1]));
            }
        }
        if (i == n) {
            Inc(ans, 1);
        } else {
            Inc(ans, Mul(Mul(fac[n - i - 1], dn), bit.Sum(t[i + 1] - 1)));
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}