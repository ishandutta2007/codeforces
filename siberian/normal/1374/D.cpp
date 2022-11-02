#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, k;
	cin >> n >> k;
	multiset<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x % k) {
			a.insert(k - x % k);
		}
	}
	int x = 0;
	ll ans = 0;
	while (!a.empty()) {
		auto it = a.lower_bound(x);
		if (it == a.end()) {
			ans += k - x;
			x = 0;
			continue;
		}
		ans += (*it) - x + 1;
		x = (*it) + 1;
		x %= k;
		a.erase(it);
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}