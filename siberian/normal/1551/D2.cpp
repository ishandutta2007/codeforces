#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(a) (a).begin(), (a).end()

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
	if (y < x) {
		x = y;
	}
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
	if (x < y) {
		x = y;
	}
}

void myFill(vector<vector<char>>& ans, int n, int m, int k) {
	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < m; j += 2) {
			if (k > 0) {
				int x = ((i / 2) + (j / 2)) % 2;
				char a = x == 0 ? 'a' : 'c';
				ans[i][j] = a;
				ans[i][j + 1] = a;
				ans[i + 1][j] = a + 1;
				ans[i + 1][j + 1] = a + 1;
				k -= 2;
				assert(k >= 0);
			} else {
				int x = ((i / 2) + (j / 2)) % 2;
				char a = x == 0 ? 'e' : 'g';
				ans[i][j] = a;
				ans[i][j + 1] = a + 1;
				ans[i + 1][j] = a;
				ans[i + 1][j + 1] = a + 1;
			}
		}
	}
}

void mySwap(vector<vector<char>>& ans) {
	vector<vector<char>> fans(ans[0].size(), vector<char>(ans.size(), '-'));
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[0].size(); ++j) {
			fans[j][i] = ans[i][j];
		}
	}	
	ans = fans;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	bool SWAP = false;
	if (m % 2 == 1) {
		SWAP = true;
		swap(n, m);
		k = n * m / 2 - k;
	}
	vector<vector<char>> ans(n, vector<char>(m, '-'));
	if (n % 2 == 0) {
		if (k % 2 == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
			return;
		}
	} else {
		k -= m / 2;
		if (k < 0) {
			cout << "NO\n";
			return;
		} else {
			if (k % 2 == 0) {
				cout << "YES\n";
				for (int i = 0; i < m; i += 2) {
					char a = i % 4 == 0 ? 'i' : 'i' + 1;
					ans[n - 1][i] = a;
					ans[n - 1][i + 1] = a;
				}
				--n;
			} else {
				cout << "NO\n";
				return;
			}
		}
	}
	myFill(ans, n, m, k);
	if (SWAP) {
		mySwap(ans);
	}
	for (auto i : ans) {
		for (auto j : i) {
			cout << j;
		}
		cout << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}