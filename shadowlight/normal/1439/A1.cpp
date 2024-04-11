#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <vector<int>> a;

void do_op(vector<pair<int, int>>& t) {
	for (auto [x, y] : t) {
		a[x][y] ^= 1;
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	a.clear();
	a.resize(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	}

	vector <vector<pair <int, int>>> res;

	for (int i = 0; i < n - 2; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j]) {
				vector<pair<int, int>> now;
				now.pb({i, j});
				now.pb({i + 1, j});
				now.pb({i + 1, (j + 1 == m ? j - 1 : j + 1)});
				res.pb(now);
				do_op(now);
			}
		}
	}

	int i = n - 2;
	for (int j = 0; j < m - 2; ++j) {
		if (a[i][j]) {
			vector<pair<int, int>> now;
			now.pb({i, j});
			now.pb({i, j + 1});
			now.pb({i + 1, j + 1});
			res.pb(now);
			do_op(now);
		}
		if (a[i + 1][j]) {
			vector<pair<int, int>> now;
			now.pb({i + 1, j});
			now.pb({i, j + 1});
			now.pb({i + 1, j + 1});
			res.pb(now);
			do_op(now);
		}
	}
	while (true) {
		int cnt = 0;
		for (int i = n - 2; i < n; ++i) {
			for (int j = m - 2; j < m; ++j) {
				cnt += a[i][j];
			}
		}
		int j = m - 2;
		//cout << "CNT: " << cnt << "\n";

		if (cnt == 4) {
			vector<pair<int, int>> now;
			now.pb({i, j});
			now.pb({i + 1, j});
			now.pb({i + 1, j + 1});
			do_op(now);
			res.pb(now);
			continue;
		}
		if (cnt == 1) {
			vector<pair<int, int>> now;
			now.pb({i, j});
			now.pb({i + 1, j});
			if (a[i][j + 1]) {
				now.pb({i, j + 1});
			} else {
				now.pb({i + 1, j + 1});
			}
			do_op(now);
			res.pb(now);
			continue;
		}
		if (cnt == 2) {
			bool was = false;
			vector<pair<int, int>> now;
			for (int i = n - 2; i < n; ++i) {
				for (int j = m - 2; j < m; ++j) {
					if (a[i][j]) {
						if (!was) {
							was = true;
							now.pb({i, j});
						}
					} else {
						now.pb({i, j});
					}
				}
			}
			do_op(now);
			res.pb(now);
			continue;
		}
		if (cnt == 3) {
			vector<pair<int, int>> now;
			for (int i = n - 2; i < n; ++i) {
				for (int j = m - 2; j < m; ++j) {
					if (a[i][j]) {
						now.pb({i, j});
					}
				}
			}
			do_op(now);
			res.pb(now);
		}
		break;
	}
	assert(res.size() <= n * m);
	cout << res.size() << "\n";
	for (auto t : res) {
		for (auto [x, y] : t) {
			cout << x + 1 << " " << y + 1 << " ";
		}
		cout << "\n";
	}
	/*cout << "A:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}*/
}

int main(){
#ifdef LOCAL
	freopen("M_input.txt", "r", stdin);
	//freopen("M_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}