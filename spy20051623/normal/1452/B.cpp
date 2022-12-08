#include <bits/stdc++.h>

using namespace std;

int a[100005];

void solve() {
	int n;
	scanf("%d", &n);
	long long sum = 0;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if (sum % (n - 1)) {
		ans += n - 1 - sum % (n - 1);
		sum += n - 1 - sum % (n - 1);
	}
	sort(a, a + n);
	if (sum < 1LL * (n - 1) * a[n - 1])
		ans += 1LL * (n - 1) * a[n - 1] - sum;
	printf("%lld\n", ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}