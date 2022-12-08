#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n + 1);
	vector<vector<int>> st0(20, vector<int>(n)), st1(20, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[a[i]] = i;
		st0[0][i] = st1[0][i] = a[i];
	}
	for (int i = 1; i < 20; ++i) {
		for (int j = 0, k = 1 << (i - 1); j <= n - (1 << i); ++j, ++k) {
			st0[i][j] = min(st0[i - 1][j], st0[i - 1][k]);
			st1[i][j] = max(st1[i - 1][j], st1[i - 1][k]);
		}
	}
	int s = 0;
	for (int i = 0; i < n - 1;) {
		if (a[i] < a[i + 1]) {
			int l = 2, r = n - i, ans;
			while (l <= r) {
				int mid = (l + r) >> 1, d = __lg(mid);
				if (min(st0[d][i], st0[d][i + mid - (1 << d)]) == a[i]) ans = mid, l = mid + 1;
				else r = mid - 1;
			}
			int x = max(st1[__lg(ans)][i], st1[__lg(ans)][i + ans - (1 << __lg(ans))]);
			++s;
			i = b[x];
		} else {
			int l = 2, r = n - i, ans;
			while (l <= r) {
				int mid = (l + r) >> 1, d = __lg(mid);
				if (max(st1[d][i], st1[d][i + mid - (1 << d)]) == a[i]) ans = mid, l = mid + 1;
				else r = mid - 1;
			}
			int x = min(st0[__lg(ans)][i], st0[__lg(ans)][i + ans - (1 << __lg(ans))]);
			++s;
			i = b[x];
		}
	}
	cout << s << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}