#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, p, k, x, y, ans = 2000000000;
		scanf("%d %d %d", &n, &p, &k);
		char a[n];
		for (int i = 0; i < n; ++i) scanf(" %c", &a[i]);
		scanf("%d %d", &x, &y);
		int cnt[k];
		fill_n(cnt, k, 0);
		for (int i = p - 1; i < n; ++i) cnt[i % k] += (a[i] == '1');
		for (int i = p - 1; i < n; ++i) {
			ans = min(ans, ((n - i - 1) / k - cnt[i % k] + 1) * x + (i - p + 1) * y);
			cnt[i % k] -= (a[i] == '1');
		}
		printf("%d\n", ans);
	}
	return 0;
}