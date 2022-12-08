#include <bits/stdc++.h>

using namespace std;

int a[30005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int l = 2e9, r = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] < r) {
			puts("NO");
			return;
		}
		a[i] -= r;
		if (a[i] <= l) l = a[i];
		else r += a[i] - l;
	}
	puts("YES");
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