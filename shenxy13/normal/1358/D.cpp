#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, l = 1;
	long long x, days = 0, ans = 0;
	scanf("%d %lld", &n, &x);
	long long a[2 * n + 1], b[2 * n + 1];
	a[0] = b[0] = 0;
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]), a[i + n] = a[i];
	for (int i = 1; i <= 2 * n; ++i) b[i] = a[i] * (a[i] + 1) / 2;
	for (int i = 1; i <= 2 * n; ++i) b[i] += b[i - 1];
	for (int i = 1; i <= 2 * n; ++i) {
		days += a[i];
		while (days > x) days -= a[l++];
		if (l == 1) {
			if (days == x) ans = max(ans, b[i]);
			continue;
		}
		ans = max(ans, b[i] - b[l - 1] + (2 * a[l - 1] - x + days + 1) * (x - days) / 2);
	}
	printf("%lld", ans);
	return 0;
}