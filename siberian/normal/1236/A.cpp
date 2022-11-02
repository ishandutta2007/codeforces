#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	while (true) {
		if (b > 0 && c > 1) {
			b--;
			c -= 2;
			ans += 3;
		}
		else if (a > 0 && b > 1) {
			a--;
			b -= 2;
			ans += 3;
		}
		else {
			break;
		}
	}
	cout << ans << endl;
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