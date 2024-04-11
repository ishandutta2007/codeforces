#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll

int n, a, b, k;

int read() {
	int x;
	cin >> x;
	x %= a + b;
	int have = x % (a + b);
	if (have == 0) x = a + b;
	if (x <= a) return 0;
	return (x - 1) / a;
}

void solve() {
	cin >> n >> a >> b >> k;
	vector<int> have;
	for (int i = 0; i < n; i++) {
		int x = read();
		//cout << x << endl;
		have.push_back(x);
	}
	sort(all(have));
	int ans = 0;
	for (auto i : have) {
		if (i > k) break;
		ans++;
		k -= i;
	}
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