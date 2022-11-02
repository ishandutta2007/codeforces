#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define fadd fadd228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n, l, v1, v2, k;

bool check(ld t) {
	if (l / t <= v1) return true;
	ld d = (ld) v2 / (v1 - v2) * (t * v1 - l);
	//cout << d << endl;
	int cnt = (n + k - 1) / k - 1;
	ld ft = d / v2;
	ld ans = ft * (cnt + 1);
	d -= v1 * ft;
	ft = d / (v1 + v2);
	ans += ft * cnt;
	//cout << ans << endl;
	return ans <= t;
}

void solve() {
	cin >> n >> l >> v1 >> v2 >> k;
	//cout << check(4) << endl;
	//return;
	ld tl = 0, tr = 1e18;
	for (int i = 0; i < 100; i++) {
		ld tm = (tl + tr) / 2;
		if (check(tm))
			tr = tm;
		else
			tl = tm;
	}
	cout.precision(20);
	cout << tr << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}