#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int a, b;
	cin >> a >> b;
	int d = abs(a - b);
	int ans = d / 5;
	d %= 5;
	ans += d / 2;
	d %= 2;
	ans += d;
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