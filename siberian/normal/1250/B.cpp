#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define fadd fadd228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll
int n, All;
vector<int> a(n);
vector<vector<int>> pos;

void solve() {
	cin >> All >> n;
	a.resize(n);
	pos.resize(All);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		pos[a[i]].push_back(i);
	}

	int ans = 0;
	for (int i = 1; i < n; i++) {
		ans += abs(a[i] - a[i - 1]);
	//	cout << a[i] << " " << a[i - 1] << endl;
	}
	int have = ans;
	//cout << "have = " << have << endl;
	for (int i = 0; i < All; i++) {
		vector<int> near;
		int fans = 0;
		for (auto j : pos[i]) {
			if (j > 0) fans += abs(i - a[j - 1]);
			if (j < n - 1) fans += abs(i - a[j + 1]);
		}
		for (auto j : pos[i]) {
	 		if (j > 0 && a[j - 1] != a[j]) {
				near.push_back(a[j - 1]);
			}
			if (j < n - 1 && a[j + 1] != a[j]) {
				near.push_back(a[j + 1]);
			}
		}
		if (near.empty()) continue;
		sort(all(near));
		int nval = near[(int)near.size() / 2];
		for (auto j : near) {
			fans -= abs(nval - j);
		}
		chkmin(ans, have - fans);
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