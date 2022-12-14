#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
long long r1, r2, r3, d, a[1000000], x[1000000], y[1000000], z[1000000], dptable[1000000][4];
long long dp(int i, int flag) {
	if (i == 0) {
		if (flag == 0) return z[0];
		if (flag == 1) return 1000000000000000000LL;
		else return min(x[0] + y[0], z[0]);
	}
	if (dptable[i][flag] != 0) return dptable[i][flag];
	if (flag == 0) return dptable[i][flag] = z[i] + min(dp(i - 1, 0), dp(i - 1, 1)) + d;
	if (flag == 1) return dptable[i][flag] = min(x[i] + y[i], z[i]) + dp(i - 1, 3) + 3 * d;
	if (flag == 2) return dptable[i][flag] = min(x[i] + y[i], z[i]) + min(min(dp(i - 1, 0), dp(i - 1, 1)) + d, dp(i - 1, 2) + 2 * d);
	return dptable[i][flag] = min(x[i] + y[i], z[i]) + min(min(dp(i - 1, 0), dp(i - 1, 1)) + d, dp(i - 1, 3) + 3 * d);
}
int main() {
	scanf("%d %lld %lld %lld %lld", &n, &r1, &r2, &r3, &d);
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	for (int i = 0; i < n; ++i) {
		x[i] = min(min(r1 * (a[i] + 1), r3 * a[i] + r1), r2);
		y[i] = min(min(r1, r3), r2);
		z[i] = min(r1 * a[i] + r3, r3 * (a[i] + 1));
	}
	int i = n - 1;
	printf("%lld", min(min(dp(n - 1, 0), dp(n - 1, 1)), dp(n - 1, 2) + min(max(0LL, z[i] - x[i] - y[i]), 2 * d)));
	return 0;
}