#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (auto &i : a)
		cin >> i.first >> i.second;
	for (auto i : a) {
		if (i.second > i.first) {
			cout << "NO\n";
			return;
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[i].first < a[i - 1].first || a[i].second < a[i - 1].second) {
			cout << "NO\n";
			return;
		}
		int d = a[i].first - a[i].second;
		int have = a[i - 1].first - a[i - 1].second;
		if (d < have) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}