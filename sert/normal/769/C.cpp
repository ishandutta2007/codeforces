#include <bits/stdc++.h>
using namespace std;

const int dc[4] = {0, -1, 1, 0};
const int dr[4] = {1, 0, 0, -1};
const string S = "DLRU";

void solve() {
	int n, m, k, r0 = -1, c0 = -1;
	cin >> n >> m >> k;
	if (k % 2) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'X') {
				r0 = i;
				c0 = j;
			}
		}
	}

	auto ok = [&](int r, int c) {
		return 0 <= r && r < n && 0 <= c && c < m && s[r][c] != '*';
	};

	vector<vector<int>> dist(n, vector<int>(m, -1));
	dist[r0][c0] = 0;
	queue<pair<int, int>> q;
	q.push({r0, c0});
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i];
			int cc = c + dc[i];
			if (!ok(rr, cc) || dist[rr][cc] != -1) continue;
			dist[rr][cc] = dist[r][c] + 1;
			q.push({rr, cc});
		}
	}

	int r = r0, c = c0;
	string path;
	for (int it = 0; dist[r][c] < k - it; it++) {
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i], cc = c + dc[i];
			if (ok(rr, cc)) {
				r = rr, c = cc;
				path.push_back(S[i]);
				break;
			}
		}
		if ((int)path.size() != it + 1) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	}

	while (r != r0 || c != c0) {
		bool okk = false;
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i], cc = c + dc[i];
			if (ok(rr, cc) && dist[rr][cc] == dist[r][c] - 1) {
				r = rr;
				c = cc;
				okk = true;
				path.push_back(S[i]);
				break;
			}
		}
		if (!okk) exit(11);
	}

	cout << path << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 3;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}