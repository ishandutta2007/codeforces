#include <bits/stdc++.h>

using namespace std;

int a[200005], c[200005];

void solve() {
	int n, k;
	cin >> n >> k;
	fill(c, c + n + 5, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		++c[a[i]];
	}
	int al = 0, ar = 1e9;
	int l = 1, r = 0, s = 0;
	while (r <= n) {
		if (s - (n - s) >= k) {
			s -= c[l++];
		} else {
			s += c[++r];
		}
		if (s - (n - s) >= k && r - l < ar - al) al = l, ar = r;
	}
	cout << al << ' ' << ar << '\n';
	l = 1, r = 0, s = 0;
	while (k > 1) {
		++r;
		if (a[r] >= al && a[r] <= ar) ++s;
		else --s;
		if (s > 0) {
			s = 0;
			cout << l << ' ' << r << '\n';
			l = r + 1;
			--k;
		}
	}
	cout << l << ' ' << n << '\n';
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