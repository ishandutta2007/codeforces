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

#define int ll

const int B = 20;

void solve() {
	ll n;
	cin >> n;
	ll ans = LONG_LONG_MAX;
	for (int cnt1 = 0; cnt1 < B; ++cnt1) {
		for (int cnt2 = 0; cnt2 < B; ++cnt2) {
			ll x = n - cnt1 * 6 - cnt2 * 8;
			chkmax(x, 0);
			chkmin(ans, cnt1 * 15 + cnt2 * 20 + (x + 9) / 10 * 25);
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