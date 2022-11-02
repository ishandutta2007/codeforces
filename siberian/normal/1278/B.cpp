#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int a, b;
	cin >> a >> b;
	int fans = abs(a - b);
	int l = -1, r = fans + 1;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if ((ll)mid * (mid + 1) / 2 >= fans) {
			r = mid;
		}
		else {
			l = mid;
		}
	}

	while (fans % 2 != ((ll)r * (r + 1) / 2) % 2)
		r++;
	cout << r << "\n";
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