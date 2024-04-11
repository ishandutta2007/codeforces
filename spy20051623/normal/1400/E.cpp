#include <bits/stdc++.h>

using namespace std;

int a[5005];

long long dfs(int l, int r, int h) {
	int mn = 1e9 + 7;
	for (int i = l; i <= r; ++i) mn = min(mn, a[i]);
	long long ans = mn - h;
	int p = l;
	while (p <= r) {
		if (a[p] == mn) {
			++p;
			continue;
		}
		int q = p + 1;
		while (q <= r && a[q] > mn) ++q;
		ans += dfs(p, q - 1, mn);
		p = q + 1;
	}
	return min(1ll * r - l + 1, ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	cout << dfs(0, n - 1, 0) << '\n';
	return 0;
}