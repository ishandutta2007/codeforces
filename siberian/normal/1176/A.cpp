#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	ll n;
	cin >> n;
	int ans = 0;
	while (n % 5 == 0) {
		n = n / 5 * 4;
		ans++;
	}
	while (n % 3 == 0) {
		n = n / 3 * 2;
		ans++;
	}
	while (n % 2 == 0 ) {
		n /= 2;
		ans++;
	}
	if (n == 1) {
		cout << ans << endl;
	}
	else {
		cout << -1 << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;	
	//t = 1;
	while (t--)
		solve();
	return 0;
}