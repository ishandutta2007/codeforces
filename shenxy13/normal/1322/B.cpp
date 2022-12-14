#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	int ans = 0;
	for (int i = 24; i >= 0; --i) {
		for (int j = 0; j < n; ++j) a[j] %= (1 << (i + 1));
		sort(a, a + n);
		long long x = 0;
		for (int j = 0; j < n; ++j) {
			x += lower_bound(a, a + n, (1 << (i + 1)) - a[j]) - lower_bound(a, a + n, (1 << i) - a[j]) + (a + n - lower_bound(a, a + n, (1 << (i + 1)) + (1 << i) - a[j]));
			if ((1 << i) <= 2 * a[j] && 2 * a[j] < (1 << (i + 1))) --x;
			if ((1 << (i + 1)) + (1 << i) <= 2 * a[j]) --x;
		}
		x /= 2;
		if (x % 2) ans += (1 << i);
	}
	printf("%d", ans);
	return 0;
}