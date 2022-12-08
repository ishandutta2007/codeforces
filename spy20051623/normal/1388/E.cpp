#include <bits/stdc++.h>

using namespace std;
const int N = 2005;
int l[N], r[N], h[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i] >> h[i];
	}
	vector<pair<double, double>> v;
	v.emplace_back(-1e18, -1e18);
	v.emplace_back(1e18, 1e18);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (h[i] >= h[j]) continue;
			v.emplace_back(1.0 * (l[j] - r[i]) / (h[j] - h[i]), 1.0 * (r[j] - l[i]) / (h[j] - h[i]));
		}
	}
	sort(v.begin(), v.end());
	int s = v.size();
	for (int i = 1; i < s - 1; ++i) {
		v[i].second = max(v[i].second, v[i - 1].second);
	}
	for (int i = s - 2; i > 0; --i) {
		v[i].first = min(v[i].first, v[i + 1].first);
	}
	double ans = 1e18;
	for (int i = 1; i < s - 1; ++i) {
		if (v[i].first >= v[i - 1].second || abs(v[i].first - v[i - 1].second) < 1e-9) {
			double x = 1e18, y = -1e18;
			for (int j = 0; j < n; ++j) {
				x = min(x, l[j] - h[j] * v[i].first);
				y = max(y, r[j] - h[j] * v[i].first);
			}
			ans = min(ans, y - x);
		}
		if (v[i].second <= v[i + 1].first || abs(v[i].second - v[i + 1].first) < 1e-9) {
			double x = 1e18, y = -1e18;
			for (int j = 0; j < n; ++j) {
				x = min(x, l[j] - h[j] * v[i].second);
				y = max(y, r[j] - h[j] * v[i].second);
			}
			ans = min(ans, y - x);
		}
	}
	if (v.size() == 2) {
		double x = 1e18, y = -1e18;
		for (int i = 0; i < n; ++i) {
			x = min(x, 1.0 * l[i]);
			y = max(y, 1.0 * r[i]);
		}
		ans = min(ans, y - x);
	}
	cout << fixed << setprecision(12) << ans;
	return 0;
}