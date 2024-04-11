#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int n, r1, r2, r3, d;
long long dp[N][2];
const long long inf = 2e18;

template <class T>
inline void chkmin(T &x, T y) {
	if (x > y) x = y;
}

int main() {
    scanf("%d %d %d %d %d", &n, &r1, &r2, &r3, &d); r1 = min(r1, r3);

    dp[0][0] = -d, dp[0][1] = inf; int a;
    for (int i = 1; i <= n; i ++) {
		scanf("%d", &a);
		dp[i][0] = dp[i][1] = inf;
		chkmin(dp[i][0], dp[i-1][0] + d + r2 + r1 + 2 * d);
		chkmin(dp[i][0], dp[i-1][0] + d + 1ll * (a + 2) * r1 + 2 * d);
		chkmin(dp[i][0], dp[i-1][0] + d + 1ll * a * r1 + r3);
		chkmin(dp[i][0], dp[i-1][1] + d + r2 + r1);
		chkmin(dp[i][0], dp[i-1][1] + d + 1ll * (a + 2) * r1);
		chkmin(dp[i][0], dp[i-1][1] + d + 1ll * a * r1 + r3);

		chkmin(dp[i][1], dp[i][0] + 2 * d);
		chkmin(dp[i][1], dp[i-1][0] + d + r2 + r1 + 2 * d);
		chkmin(dp[i][1], dp[i-1][0] + d + 1ll * (a + 2) * r1 + 2 * d);

    }
    printf("%lld\n", min(dp[n][0], min(dp[n][1], dp[n-1][1] + 1ll * a * r1 + r3)));

    return 0;
}