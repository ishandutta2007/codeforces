#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 30;

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

int n, a[N], b[N];
LL dp[N][2];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
    }
    dp[1][0] = dp[1][1] = 0;
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = min(dp[i - 1][0] + abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]),
                       dp[i - 1][1] + abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]));
        dp[i][1] = min(dp[i - 1][0] + abs(b[i] - a[i - 1]) + abs(a[i] - b[i - 1]),
                       dp[i - 1][1] + abs(b[i] - b[i - 1]) + abs(a[i] - a[i - 1]));
    }
    printf("%lld\n", min(dp[n][0], dp[n][1]));
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}