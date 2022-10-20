#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 1005;

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
    const int MOD = 1e9 + 7;
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

LL L, R, Z;
int n, dp[65][N], C[N][N];

int Calc(LL lim) {
    if (lim < Z) return 0;
    lim = (lim - Z) / 2;
    mset(dp, 0);
    dp[60][(lim >> 59) & 1] = 1;
    int ret = 0;
    for (int i = 60; i >= 0; --i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= j; ++k) {
                int cnt = (k << 1) + ((Z >> i) & 1);
                int cur = Mul(dp[i][j], C[n][cnt]);
                if (i > 0) {
                    int nxt = ((j - k) << 1) | ((lim >> (i - 1)) & 1);
                    Inc(dp[i - 1][min(n, nxt)], cur);
                } else {
                    Inc(ret, cur);
                }
            }
        }
    }
    return ret;
}

void solve() {
    read(n); read(L); read(R); read(Z);
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = Add(C[i - 1][j], C[i - 1][j - 1]);
        }
    }
    printf("%d\n", Sub(Calc(R), Calc(L - 1)));
}

int main() {
    solve();
    return 0;
}