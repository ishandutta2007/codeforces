#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[200005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i].first);
		sum += a[i].first;
		a[i].second = i;
	}
	sort(a, a + n);
	long long ans = -2e18, cnt = 0;
	if (n % 3 == 1) ans = sum;
	for (int i = 0; i < n; ++i) {
		sum += -2 * a[i].first;
		if (a[i].second & 1) ++cnt;
		if ((n + i + 1) % 3 == 1) {
			if (cnt == n / 2 && i == cnt - 1) {
				if (i < n - 1) ans = max(ans, sum + 2 * a[i].first - 2 * a[i + 1].first);
			} else {
				ans = max(ans, sum);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}