#include <bits/stdc++.h>

using namespace std;

int a[200005], b[200005];
int n;

bool check(int x) {
	int p = 0;
	for (int i = 0; i < n; ++i) {
		if (b[i] >= p && a[i] >= x - p - 1) ++p;
		if (p == x) return true;
	}
	return false;
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
	}
	int l = 1, r = n, ans;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (check(m)) ans = m, l = m + 1;
		else r = m - 1;
	}
	printf("%d\n", ans);
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