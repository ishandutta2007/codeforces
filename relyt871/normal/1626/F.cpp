#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 10000005;
const int LCM = 720720;

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

int n, a[MAXN], x, y, k, M;
int dp[20][LCM + 5], pw[20];

void solve() {
    read(n); read(a[0]); read(x); read(y);
    read(k); read(M);
    for (int i = 1; i < n; ++i) {
        a[i] = (1LL * a[i - 1] * x + y) % M;
    }
    pw[0] = 1;
    for (int i = 1; i <= k; ++i) {
        pw[i] = Mul(pw[i - 1], n);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        Inc(dp[0][a[i] % LCM], 1);
        a[i] -= a[i] % LCM;
        Inc(ans, Mul(a[i], Mul(pw[k - 1], k)));
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < LCM; ++j) {
            Inc(ans, Mul(dp[i - 1][j], Mul(j, pw[k - i])));
            Inc(dp[i][j], Mul(dp[i - 1][j], n - 1));
            Inc(dp[i][j - j % i], dp[i - 1][j]);
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
	return 0;
}