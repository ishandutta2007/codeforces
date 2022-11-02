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
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	n += a + b + c;
	if (n % 3) {
		cout << "NO\n";
		return;
	}
	n /= 3;
	if (n < max(max(a, b), c)) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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