#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 1000005;

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

int dp[42][15][15][15], ans[42][15][15];

void prework() {
    dp[0][0][0][0] = 1;
    for (int i = 1; i <= 40; ++i) {
        for (int k = 0; k <= 11; ++k) {
            for (int x = 0; x <= 11; ++x) {
                for (int j = 0; j < i && j <= 11; ++j) {
                    for (int t = 0; t < i && t <= 11; ++t) {
                        if (k + t > 11) continue;
                        if (x + (j < t) > 11) continue;
                        Inc(dp[i][k + t][x + (j < t)][t], dp[i - 1][k][x][j]);
                    }
                }
                for (int j = 0; j <= 11; ++j) {
                    Inc(ans[i][k][x], dp[i][k][x][j]);
                }
            }
        }
    }
}

namespace Lagrange {
    int Calc(int k, int *x, int *y, int n) {
        int ret = 0;
        for (int i = 1; i <= k; ++i) {
            int up = y[i], dn = 1;
            for (int j = 1; j <= k; ++j) {
                if (i == j) continue;
                up = Mul(up, Sub(n, x[j]));
                dn = Mul(dn, Sub(x[i], x[j]));
            }
            Inc(ret, Mul(up, Inv(dn)));
        }
        return ret;
    }
}

int n, k, x, X[30], Y[30];

void solve() {
    int n, k, x;
    read(n); read(k); read(x);
    if (n <= 40) {
        printf("%d\n", ans[n][k][x]);
    } else {
        for (int i = 1; i <= 20; ++i) {
            X[i] = 20 + i;
            Y[i] = ans[20 + i][k][x];
        }
        printf("%d\n", Lagrange::Calc(20, X, Y, n));
    }
}

int main() {
    prework();
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}