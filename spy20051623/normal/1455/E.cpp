#include <bits/stdc++.h>

using namespace std;
int x[4], y[4];

long long calc(int a) {
	int k[] = {0, 1, 2, 3}, xx[4], yy[4];
	long long res = 1e18;
	for (int i = 0; i < 24; ++i) {
		memcpy(xx, x, sizeof x);
		memcpy(yy, y, sizeof y);
		for (int j = 0; j < 4; ++j) {
			if (k[j] & 1) xx[j] -= a;
			if (k[j] > 1) yy[j] -= a;
		}
		sort(xx, xx + 4);
		sort(yy, yy + 4);
		long long sum = 0;
		for (int j = 0; j < 4; ++j) {
			sum += abs(xx[j] - xx[1]);
			sum += abs(yy[j] - yy[1]);
		}
		res = min(res, sum);
		next_permutation(k, k + 4);
	}
	return res;
}

void solve() {
	for (int i = 0; i < 4; ++i) cin >> x[i] >> y[i];
	int l = 1, r = 1e9 + 10;
	long long ans = 1e18;
	while (l <= r) {
		int ml = l + (r - l) / 3, mr = r - (r - l) / 3;
		long long al = calc(ml), ar = calc(mr);
		if (al < ar) {
			if (al < ans) ans = al;
			r = mr - 1;
		} else {
			if (ar < ans) ans = ar;
			l = ml + 1;
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