#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int32_t main() {
	int n, m;
	scanf("%lld %lld", &n, &m);
	int a[n + 1];
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	a[n] = 0;
	sort(a, a + n + 1);
	for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
	int ans[n + 1];
	for (int i = 0; i < m; ++i) {
		ans[i] = a[i];
		for (int j = m + i; j <= n; j += m) ans[j] = ans[j - m] + a[j];
	}
	for (int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
	return 0;
}