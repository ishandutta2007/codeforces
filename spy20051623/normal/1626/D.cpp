#include <bits/stdc++.h>

using namespace std;

int c[200005];

int calc(int x) {
	int y = 1;
	while (y < x) {
		y <<= 1;
	}
	return y;
}

void solve() {
	int n;
	cin >> n;
	fill(c, c + n + 5, 0);
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		++c[p];
	}
	int tot = 0;
	vector<int> v(1, 0);
	for (int i = 1; i <= n; ++i) {
		if (c[i]) {
			tot += c[i];
			v.push_back(tot);
		}
	}
	int ans = 2e9;
	for (int i = 1; i == 1 || i <= n; i <<= 1) {
		int p1 = *--upper_bound(v.begin(), v.end(), i);
		for (int j = 1; j == 1 || j <= n - p1; j <<= 1) {
			int p2 = *--upper_bound(v.begin(), v.end(), p1 + j);
			int n1 = max(0, p1), n2 = max(0, p2 - p1), n3 = max(0, n - p2);
			ans = min(ans, calc(n1) - n1 + calc(n2) - n2 + calc(n3) - n3);
		}
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