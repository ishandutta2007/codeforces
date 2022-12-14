#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	long long k, a[n];
	scanf("%lld", &k);
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	sort(a, a + n);
	long long ans = a[n - 1] - a[0];
	int x = 1;
	while (k != 0) {
		if (x > (n - 1) / 2) break;
		if (k >= (a[x] - a[x - 1] + a[n - x] - a[n - x - 1]) * x) {
			ans -= a[x] - a[x - 1] + a[n - x] - a[n - x - 1];
			k -= x * (a[x] - a[x - 1] + a[n - x] - a[n - x - 1]);
		} else {
			ans -= k / x;
			printf("%lld", ans);
			return 0;
		}
		++x;
	}
	if (k != 0 && n % 2 == 0) {
		if (k >= ((n - 1) / 2 + 1) * (a[(n - 1) / 2 + 1] - a[(n - 1) / 2])) {
			printf("0");
		} else printf("%lld", ans - k / ((n - 1) / 2 + 1));
		return 0;
	}
	printf("%lld", ans);
	return 0;
}