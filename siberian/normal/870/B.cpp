#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;
	if (k == 1) {
		cout << *min_element(all(a));
	}
	else if (k > 2) {
	cout << *max_element(all(a));
		
	}
	else {
		vector<int> pref = a;
		for (int i = 1; i < n; i++)
			chkmin(pref[i], pref[i - 1]);
		vector<int> suff = a;
		for (int i = n - 2; i >= 0; i--)
			chkmin(suff[i], suff[i + 1]);
		int ans = -2e9;
		for (int i = 0; i < n - 1; i++) {
			chkmax(ans, max(pref[i], suff[i + 1]));
		}
		cout << ans;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	//cin >> t;	
	t = 1;
	while (t--)
		solve();
	return 0;
}