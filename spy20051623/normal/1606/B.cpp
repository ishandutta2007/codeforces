#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n, k;
	scanf("%lld%lld", &n, &k);
	long long cur = 1, ans = 0;
	while (cur < k && cur < n) {
		cur <<= 1, ++ans;
	}
	if (cur < n) {
		ans += (n - cur - 1) / k + 1;
	}
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