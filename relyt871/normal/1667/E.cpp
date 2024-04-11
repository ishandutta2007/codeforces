#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = (1 << 19) + 5;

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

int n, m, fac[MAXN], finv[MAXN], f[MAXN], ans[MAXN];
int A[MAXN], B[MAXN];

int len, rev[MAXN], w1[MAXN], w2[MAXN];

inline int C(int x, int y) {
    return Mul(fac[x], Mul(finv[y], finv[x - y]));
}

void prework(int m) {
    int bit = -1;
    for (len = 1; len < m; len <<= 1) ++bit;
    for (int i = 0; i < len; ++i) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << bit);
    }
    int Gi = 3, Gv = Inv(Gi);
    for (int i = 1; i < len; i <<= 1) {
        int wk1 = Ksm(Gi, (MOD - 1) / (i << 1)), wnk1 = 1;
        int wk2 = Ksm(Gv, (MOD - 1) / (i << 1)), wnk2 = 1;
        for (int k = 0; k < i; ++k) {
            w1[i + k] = wnk1;
            wnk1 = Mul(wnk1, wk1);
            w2[i + k] = wnk2;
            wnk2 = Mul(wnk2, wk2);
        }
    }
}

void NTT(int *a, int type) {
    int *w = (type == 1? w1 : w2);
    for (int i = 0; i < len; ++i) {
        if (i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }
    for (int i = 1; i < len; i <<= 1) {
        for (int j = 0; j < len; j += (i << 1)) {
            for (int k = 0; k < i; ++k) {
                int x = a[j + k], y = Mul(a[j + k + i], w[i + k]);
                a[j + k] = Add(x, y);
                a[j + k + i] = Sub(x, y);
            }
        }
    }
    if (type == 1) return;
    int lenv = Inv(len);
    for (int i = 0; i < len; ++i) {
        a[i] = Mul(a[i], lenv);
    }
}

void solve() {
    read(n);
    m = n / 2;

    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = Mul(fac[i - 1], i);
    }
    finv[n] = Inv(fac[n]);
    for (int i = n; i >= 1; --i) {
        finv[i - 1] = Mul(finv[i], i);
    }
    prework((n + 1) << 1);

    f[0] = 1;
    int sum = 1;
    for (int i = 1; i <= n; ++i) {
        if (i >= m + 1) {
            Dec(sum, Mul(f[i - m - 1], finv[i - m - 1]));
        }
        f[i] = Mul(sum, fac[i - 1]);
        Inc(sum, Mul(f[i], finv[i]));
    }

    for (int i = m; i <= n - 2; ++i) {
        A[i] = Mul(Mul(fac[n - i - 2], finv[i]), f[i]);
    }
    for (int i = 0; i <= n; ++i) {
        B[i] = finv[i];
    }
    NTT(A, 1); NTT(B, 1);
    for (int i = 0; i < len; ++i) {
        A[i] = Mul(A[i], B[i]);
    }
    NTT(A, -1);

    ans[1] = f[n - 1];
    for (int i = 2; i <= m + 1; ++i) {
        ans[i] = Mul(i - 1, Mul(fac[n - i], A[n - i]));
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
}

int main() {
    solve();
    return 0;
}