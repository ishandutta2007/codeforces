#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
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
	int n;
	cin >> n;
	vector<int> a(n - 1);
	for (auto &i : a)
		cin >> i;
	vector<int> ans(n, 1);
	for (int i = 1; i < n; i++) {
		ans[i] = ans[i - 1] + a[i - 1];
	}	
	int m = *min_element(all(ans));
	for (auto &i : ans) i += 1 - m;
	set<int> have;
	for (auto i : ans) have.insert(i);
	for (int i = 1; i <= n; i++) {
		if (!have.count(i)) {
			cout << -1;
			return;
		}
	}
	for (auto i : ans) cout << i << " ";
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