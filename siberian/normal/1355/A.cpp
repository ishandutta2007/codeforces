#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

pair<int, int> get(int x) {
	pair<int, int> ans = {9, 0};
	while (x) {
		chkmin(ans.first, x % 10);
		chkmax(ans.second, x % 10);
		x /= 10;
	}
	return ans;
}

void solve() {
	int a, k;
	cin >> a >> k;
	k--;
	while (k--) {
		auto have = get(a);
		if (have.first == 0 || have.second == 0) break;
		a += have.first * have.second;
	}
	cout << a << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}