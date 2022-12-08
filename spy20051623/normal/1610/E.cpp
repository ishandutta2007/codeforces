#include <bits/stdc++.h>

using namespace std;

int a[200005];
int n;

int dfs(int p, int d) {
	if (p == d) {
		int r = upper_bound(a + p + 1, a + n, a[p]) - a - 1;
		if (r > p) return r - p + dfs(r, d);
	}
	int to = lower_bound(a + p + 1, a + n, a[p] + a[p] - a[d]) - a;
	if (to == n) return 1;
	else return 1 + dfs(to, d);
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, dfs(i, i));
	}
	printf("%d\n", n - ans);
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