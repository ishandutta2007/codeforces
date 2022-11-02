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
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	ll ans = LONG_LONG_MIN;
	for (int i = 0; i < n; ++i) {
		for (int j = i - 1; j >= 0 && i - j < 500; --j) {
			chkmax(ans, (ll)(i + 1) * (j + 1) - (ll)k * (a[i] | a[j]));
		}
	}
	cout << ans << '\n';
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