#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	map<int, int> mp;
	for (int i = 0; i < n - 1; ++i) {
		int p;
		cin >> p;
		++a[p];
	}
	a[0] = 1;
	sort(a.begin(), a.end());
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int m = (l + r) >> 1;
		int h = m, c = 0;
		for (int i = n; i >= 0; --i) {
			if (!a[i]) break;
			if (a[i] <= h) ++c;
			else c += 1 + a[i] - h;
			--h;
		}
		if (c <= m) ans = m, r = m - 1;
		else l = m + 1;
	}
	cout << ans << '\n';
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