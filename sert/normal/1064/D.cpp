#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

void solve() {
	int n, m, r, c, x, y;
	cin >> n >> m;
	cin >> r >> c >> x >> y;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	r--;
	c--;

	deque<pair<int, int>> q;
	vector<vector<int>> d(n, vector<int>(m, INF));

	d[r][c] = 0;
	q.push_back(make_pair(r, c));
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop_front();

		for (int dy = -1; dy <= 1; dy += 2) {
			if (0 <= r + dy && r + dy < n && d[r + dy][c] == INF && a[r + dy][c] == '.') {
				d[r + dy][c] = d[r][c];
				q.push_front(make_pair(r + dy, c));
			}
		}

		for (int dx = -1; dx <= 1; dx += 2) {
			if (0 <= c + dx && c + dx < m && d[r][c + dx] == INF && a[r][c + dx] == '.') {
				d[r][c + dx] = d[r][c] + 1;
				q.push_back(make_pair(r, c + dx));
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != '.') continue;
			int moves = d[i][j];
			int xx = 0;
			int yy = 0;
			if (j < c) {
				moves -= (c - j);
				xx += (c - j);
			} else {
				moves -= (j - c);
				yy += (j - c);				
			}
			xx += moves / 2;
			yy += moves / 2;

			if (xx <= x && yy <= y) {
				ans++;
			}
		}
	}

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 2;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}