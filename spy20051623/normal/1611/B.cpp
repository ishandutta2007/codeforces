#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long a, b;
	scanf("%lld%lld", &a, &b);
	if (a >= b * 3) {
		printf("%lld\n", b);
		return;
	}
	if (b >= a * 3) {
		printf("%lld\n", a);
		return;
	}
	printf("%lld\n", (a + b) / 4);
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