#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long x, n;
	scanf("%lld%lld", &x, &n);
	for (long long i = n / 4 * 4 + 1; i <= n; ++i) {
		if (x & 1) x += i;
		else x -= i;
	}
	printf("%lld\n", x);
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