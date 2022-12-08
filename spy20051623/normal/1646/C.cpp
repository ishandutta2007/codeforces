#include <bits/stdc++.h>

using namespace std;

long long fac[100];
vector<pair<long long, int>> v;

int popcount(long long x) {
	int y = 0;
	while (x) {
		y += x & 1;
		x >>= 1;
	}
	return y;
}

void solve() {
	long long n;
	cin >> n;
	int ans = 100000;
	for (auto i: v) {
		if (i.first > n) break;
		ans = min(ans, i.second + popcount(n - i.first));
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
	fac[1] = 1;
	for (int i = 2; i <= 15; ++i) {
		fac[i] = fac[i - 1] * i;
	}
	v.emplace_back(0, 0);
	for (int i = 3; i <= 15; ++i) {
		int sz = v.size();
		v.emplace_back(fac[i], 1);
		for (int j = 0; j < sz; ++j) {
			v.emplace_back(v[j].first + fac[i], v[j].second + 1);
		}
	}
	sort(v.begin(), v.end());
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}