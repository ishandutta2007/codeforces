#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	if (a > b * c) {
		puts("-1");
		return;
	}
	long long p = min((a - 1) / (b * d), c / d);
	long long h = b * d;
	long long ans = (p + 1) * a - (p + 1) * p / 2 * h;
	printf("%lld\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}