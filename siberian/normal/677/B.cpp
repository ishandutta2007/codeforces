#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll

int nxt(int k, int need) {
	int l = -1, r = 1e9 + 10;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (need <= k * mid)
			r = mid;
		else
			l = mid;
	}
	return r;
}

void solve() {
	int n, k, h;
	cin >> n >> h >> k;
	int ans = 0;
	int now = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int need = nxt(k, x - (h - now));
		ans += need;
		now -= need * k;
		now = max(0LL, now);
		now += x;
	}
	ans += nxt(k, now);
	cout << ans;
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