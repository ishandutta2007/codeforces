#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
int n;
vector<int> a;

int solve(int l, int r) {
	int ans = 0;
	int pref = 0;
	int mn = 0;
	for (int i = l; i <= r; i++) {
		pref += a[i];
		chkmin(mn, pref);
		chkmax(ans, pref - mn);
	}
	return ans;
}

int solve(int MAX_VAL) {
	if (MAX_VAL <= 0) return 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > MAX_VAL) continue;
		int r = i;
		while (r < n && a[r] <= MAX_VAL) r++;
		r--;
		chkmax(ans, solve(i, r) - MAX_VAL);
		i = r;
	}
	return ans;
}

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
	}
	vector<int> have = a;
	sort(all(have));
	have.resize(unique(all(have)) - have.begin());
	int ans = 0;
	for (auto i : have) {
		chkmax(ans, solve(i));
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}