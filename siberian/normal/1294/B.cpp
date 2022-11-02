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
	vector<pair<int, int> > a(n);
	for (auto &i : a)
		cin >> i.first >> i.second;
	sort(all(a));
	string ans = "";
	pair<int, int> last = {0, 0};
	for (auto i : a) {
		if (i.first < last.first || i.second < last.second) {
			cout << "NO\n";
			return;
		}
		for (int j = 0; j < i.first - last.first; j++)
			ans += "R";
		for (int j = 0; j < i.second - last.second; j++)
			ans += "U";
		last = i;
	}
	cout << "YES\n";
	cout << ans << "\n";
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