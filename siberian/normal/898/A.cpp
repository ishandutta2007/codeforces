#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n;
	cin >> n;
	if (n % 10 > 5) {
		cout << n / 10 * 10 + 10;
	}
	else {
		cout << n / 10 * 10;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	//cin >> t;	
	t = 1;
	while (t--)
		solve();
	return 0;
}