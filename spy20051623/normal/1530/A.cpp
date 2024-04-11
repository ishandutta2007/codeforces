#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	while (n) {
		ans = max(ans, n % 10);
		n /= 10;
	}
	printf("%d\n", ans);
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