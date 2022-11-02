#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(a) (a).begin(), (a).end()

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
	if (y < x) {
		x = y;
	}
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
	if (x < y) {
		x = y;
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	map<int, vector<int>> pos;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (pos[x].size() < k) {
			pos[x].push_back(i);
			++cnt;
		}
	}
	cnt -= cnt % k;
	vector<int> ans(n);
	for (int i = 1; i <= cnt / k; ++i) {
		int have = 0;
		while (have < k) {
			auto it = pos.begin();
			if (it->second.empty()) {
				pos.erase(it);
				continue;
			}
			++have;
			ans[it->second.back()] = have;
			it->second.pop_back();
		}
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}