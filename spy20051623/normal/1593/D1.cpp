#include <bits/stdc++.h>

using namespace std;

int a[100];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int minm = a[0], maxm = a[0];
	for (int i = 1; i < n; ++i) {
		minm = min(minm, a[i]);
		maxm = max(maxm, a[i]);
	}
	if (minm == maxm) {
		puts("-1");
		return;
	}
	int ans = maxm - minm;
	for (int i = 0; i < n; ++i) {
		if (a[i] != minm) ans = __gcd(ans, a[i] - minm);
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