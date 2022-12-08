#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	if (a[1] != n && a[n] != n) {
		puts("-1");
		return;
	}
	if (a[1] == n) {
		for (int i = n; i >= 2; --i) {
			printf("%d ", a[i]);
		}
		printf("%d\n", n);
	} else {
		for (int i = n - 1; i >= 1; --i) {
			printf("%d ", a[i]);
		}
		printf("%d\n", n);
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