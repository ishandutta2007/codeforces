#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1e6  + 10;

void solve() {
	int n, m;
	cin >> n >> m;
	int l = 1, r = n;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		chkmax(l, a);
		chkmin(r, b);
	}
	if (l > r) cout << 0;
	else cout << r - l;
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