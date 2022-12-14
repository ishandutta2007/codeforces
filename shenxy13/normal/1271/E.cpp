#include <cstdio>
#include <algorithm>
using namespace std;
long long n, k;
bool check(long long x) {
	long long ans = 0, a = x, b = x;
	if (x % 2 == 0) b = x + 1;
	while (b <= n) {
		ans += b - a + 1;
		a *= 2;
		b = 2 * b + 1;
	}
	ans += max(0LL, n - a + 1);
	return ans >= k;
}
int main() {
	scanf("%lld %lld", &n, &k);
	long long l, u, m, ans;
	l = 0, u = n;
	while (l != u) {
		m = (l + u) / 2 + 1;
		if (check(2 * m + 1)) l = m;
		else u = m - 1;
	}
	ans = 2 * l + 1;
	l = 1, u = n;
	while (l != u) {
		m = (l + u) / 2 + 1;
		if (check(2 * m)) l = m;
		else u = m - 1;
	}
	if (check(2 * l)) ans = max(ans, 2 * l);
	printf("%lld", ans);
	return 0;
}