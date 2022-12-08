#include <bits/stdc++.h>

using namespace std;

int a[105], c[105];

void solve() {
	memset(c, 0, sizeof c);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i], ++c[a[i]];
	int p = 0;
	while (c[p]) --c[p++];
	int q = 0;
	while (c[q]) ++q;
	cout << p + q << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}