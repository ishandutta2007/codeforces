#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

vector<char> good;

void build() {
	for (int i = 0; i < 26; i++)
		good.push_back('a' + i);
	for (int i = 0; i < 26; i++)
		good.push_back('A' + i);
	for (int i = 0; i < 10; i++)
		good.push_back('0' + i);
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<char> > table(n, vector<char> (m));
	int cnt = 0;
	for (auto &i : table) {
		for (auto &j : i) {
			cin >> j;
			cnt += (j == 'R');
		}
	}

	vector<vector<char> > ans(n, vector<char> (m));

	int need = cnt / k;
	int more = cnt % k;
	int now = 0;
	int have = 0;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; j++) {
				ans[i][j] = good[now];
				have += (table[i][j] == 'R');
				if (have == need && more == 0) {
					now++;
					now = min(now, k - 1);
					have = 0;
				}
				else if (have == need + 1 && more > 0) {
					now++;
					now = min(now, k - 1);
					have = 0;
					more--;
				}
			}
		}
		else {
			for (int j = m - 1; j >= 0; j--) {
				ans[i][j] = good[now];
				have += (table[i][j] == 'R');
				if (have == need && more == 0) {
					now++;
					now = min(now, k - 1);
					have = 0;
				}
				else if (have == need + 1 && more > 0) {
					now++;
					now = min(now, k - 1);
					have = 0;
					more--;
				}
			}
		}
	}
	for (auto i : ans) {
		for (auto j : i)
			cout << j;
		cout << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	build();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}