#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = n + 1; i <= n + n; ++i) {
		printf("%d ", i << 1);
	}
	puts("");
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