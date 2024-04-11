#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2005;

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

namespace ModCalculator {
    const int MOD = 1e9 + 7;
    const int INV2 = 5e8 + 4;
    inline void Inc(int &x, int y) {
        x += y; if (x >= MOD) x -= MOD;
    }
    inline int Add(int x, int y)  {
        Inc(x, y); return x;
    }
    inline int Mul(int x, int y) {
        return 1LL * x * y % MOD;
    }
}
using namespace ModCalculator;

int n, m, k, dp[N][N];

void solve() {
    read(n); read(m); read(k);
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 0;
        dp[i][i] = Mul(i, k);
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i && j <= m; ++j) {
            dp[i][j] = Add(dp[i - 1][j], dp[i - 1][j - 1]);
            dp[i][j] = Mul(dp[i][j], INV2);
        }
    }
    printf("%d\n", dp[n][m]);
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}