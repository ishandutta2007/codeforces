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
	int cnt = 0;
	vector<vector<char>> ans(n, vector<char> (n, 'S'));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 2 == 0) {
				if (cnt < k) {
					ans[i][j] = 'L';
					cnt++;
				}
			}
		}
	}
	if (cnt < k) {
		cout << "NO";
		return;
	}
	cout << "YES\n";
	for (auto i : ans) {
		for (auto j : i)
			cout << j;
		cout << endl;
	}
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