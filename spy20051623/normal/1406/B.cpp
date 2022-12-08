#include <bits/stdc++.h>

using namespace std;

int a[100005];

void solve() {
	int n;
	cin >> n;
	bool neg = true;
	vector<int> v(5, 0), u(5, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] >= 0) neg = false, v.push_back(a[i]);
		else u.push_back(-a[i]);
	}
	long long ans = 1;
	if (n == 5) {
		for (int i = 0; i < 5; ++i) {
			ans *= a[i];
		}
		cout << ans << '\n';
		return;
	}
	sort(v.begin(), v.end());
	sort(u.begin(), u.end());
	if (neg) {
		ans = -1;
		for (int i = 0; i < 5; ++i) {
			ans *= u[5 + i];
		}
	} else {
		ans *= v.back();
		v.pop_back();
		int x = v.size(), y = u.size();
		if (v[x - 1] * v[x - 2] > u[y - 1] * u[y - 2]) {
			ans *= v[x - 1] * v[x - 2];
			v.pop_back();
			v.pop_back();
		} else {
			ans *= u[y - 1] * u[y - 2];
			u.pop_back();
			u.pop_back();
		}
		x = v.size(), y = u.size();
		if (v[x - 1] * v[x - 2] > u[y - 1] * u[y - 2]) {
			ans *= v[x - 1] * v[x - 2];
			v.pop_back();
			v.pop_back();
		} else {
			ans *= u[y - 1] * u[y - 2];
			u.pop_back();
			u.pop_back();
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