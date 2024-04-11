#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

void solve() {
	int a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	int l = 0, r = a + 1;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (a - mid <= b - 2 * mid) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int ans = l;
	a -= l;
	b -= 2 * l;
	int fa = a % 3;
	a -= fa;
	int fb = b % 3;
	b -= fb;
	ans += a / 3 * 2;
	if (min(fa, fb) >= 1 && max(fa, fb) >= 2) {
		ans++;
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