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
	vector<int> a(n), b(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	int ans = 1e18;
	for (int i = 0; i < n; i++) {
		vector<int> c = a;
		int x = (((b[i] - a[0] + m) % m) + m) % m;
		for (auto &j : c){
			j += x;
			j %= m;
		}
		vector<int> d = b;
		sort(all(c));
		sort(all(d));
		if (c==d) chkmin(ans, x);
	}

	if (ans == 1e18) ans = -1;
	cout << ans << endl;
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