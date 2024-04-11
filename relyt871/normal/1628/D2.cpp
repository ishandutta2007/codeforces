#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 5;

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
    const int MOD = 1e9 + 7;
    const int INV2 = 5e8 + 4;
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
    inline int Sqr(int x) {
        return 1LL * x * x % MOD;
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

int n, m, k, fac[MAXN], finv[MAXN], pw[MAXN];

void prework() {
    n = 1000000;
    fac[0] = pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = Mul(fac[i - 1], i);
        pw[i] = Mul(pw[i - 1], INV2);
    }
    finv[n] = Inv(fac[n]);
    for (int i = n; i >= 1; --i) {
        finv[i - 1] = Mul(finv[i], i);
    }
}

inline int C(int x, int y) {
    return Mul(fac[x], Mul(finv[y], finv[x - y]));
}

void solve() {
    read(n); read(m); read(k);
    if (n == m) {
        printf("%d\n", Mul(n, k));
        return;
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int x = Mul(Mul(i, k), pw[n - i]);
        Inc(ans, Mul(x, C(n - i - 1, m - i)));
    }
    printf("%d\n", ans);
}

int main() {
    prework();
    int T; scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}