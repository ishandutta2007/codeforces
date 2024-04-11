#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
const int INF = 1e18;
void solve() {
	int n;
	cin >> n;
	int l = -INF;
	int r = INF;
	vector<pair<int, int>> a(n);
	for (auto &i : a)
		cin >> i.first >> i.second;
	int now = 0;
	for (auto i : a) {
		if (i.second == 1) {
			chkmax(l, 1899 - now);
		}
		else {
			chkmin(r, 1900 - now);
		}
		now += i.first;
	}
	if (l >= r - 1) {
		cout << "Impossible";
		return;
	}
	if (r == INF) {
		cout << "Infinity";
		return;
	}
	r += now;	
	cout << r - 1;
	//cout << l << " " << r << " " << now << endl;
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