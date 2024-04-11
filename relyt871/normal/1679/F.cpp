#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXS = (1 << 10);

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

int n, m;
int g[10], g2[10], dp[2][MAXS];

void solve() {
    read(n); read(m);
    for (int i = 1, u, v; i <= m; ++i) {
        read(u); read(v);
        g[u] |= (1 << v);
        g[v] |= (1 << u);
        g2[u] |= (1 << v);
    }
    dp[0][0] = 1;
    int pre = 0, cur = 1;
    for (int i = 1; i <= n; ++i) {
        mset(dp[cur], 0);
        for (int s = 0; s < MAXS; ++s) {
            if (!dp[pre][s]) continue;
            for (int j = 0; j < 10; ++j) {
                if ((s >> j) & 1) continue;
                Inc(dp[cur][g2[j] | (s & g[j])], dp[pre][s]);
            }
        }
        swap(pre, cur);
    }
    int ans = 0;
    for (int s = 0; s < MAXS; ++s) {
        Inc(ans, dp[pre][s]);
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}