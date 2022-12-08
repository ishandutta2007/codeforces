#include <bits/stdc++.h>

using namespace std;

int a[100005];

void solve() {
	int n, h, m, k;
	cin >> n >> h >> m >> k;
	map<int, int> mp, s;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if (y >= m / 2) y -= m / 2;
		a[i] = y;
		++mp[y];
		mp[(y - 1 + m / 2) % (m / 2)];
		mp[(y - k + m / 2) % (m / 2)];
	}
	int l = 0;
	for (auto i: mp) {
		s[i.first] = s[l] + i.second;
		l = i.first;
	}
	int ans, num = 1e9;
	for (auto i: mp) {
		if (!i.second) continue;
		int x = i.first, y;
		if (x < k) y = s[x - 1] + n - s[x + m / 2 - k];
		else y = s[x - 1] - s[x - k];
		if (y < num) ans = x, num = y;
	}
	cout << num << ' ' << ans << '\n';
	for (int i = 0; i < n; ++i) {
		if (a[i] > ans - k && a[i] < ans || a[i] > ans - k + m / 2 && a[i] < ans + m / 2) cout << i + 1 << ' ';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}