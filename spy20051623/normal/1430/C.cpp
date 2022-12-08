#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	puts("2");
	printf("%d %d\n", n, n - 1);
	for (int i = n - 2; i >= 1; --i) {
		printf("%d %d\n", i, i + 2);
	}
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