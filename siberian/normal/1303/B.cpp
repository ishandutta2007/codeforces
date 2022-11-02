#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll

bool check(int d, int n, int g, int b) {
	int have = d / (g + b) * g;
	int x = d % (g + b);
	if (x > g) x = g;
	have += x;
	return have >= n;
}

void solve() {
	int n, g, b;
	cin >> n >> g >> b;
	int l = n - 1, r = 3e18;
	n = (n + 1) / 2;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (check(mid, n, g, b))
			r = mid;
		else
			l = mid;
	}
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