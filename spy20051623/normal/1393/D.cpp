#include <bits/stdc++.h>

using namespace std;
const int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
char mp[2005][2005];
int n, m;

long long work(char c) {
	int cnt = 0;
	long long ans = 0;
	vector<pair<int, int>> v, vv;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (mp[i][j] == c) {
				++cnt;
				for (auto k: dir) {
					if (mp[i + k[0]][j + k[1]] != c) {
						v.emplace_back(i, j);
						break;
					}
				}
			}
		}
	}
	for (auto p: v) {
		int i = p.first, j = p.second;
		mp[i][j] = 0;
	}
	while (cnt > 0) {
		ans += cnt;
		cnt -= v.size();
		for (auto p: v) {
			int i = p.first, j = p.second;
			for (auto k: dir) {
				if (mp[i + k[0]][j + k[1]] == c) {
					mp[i + k[0]][j + k[1]] = 0;
					vv.emplace_back(i + k[0], j + k[1]);
				}
			}
		}
		v = vv;
		vv.clear();
	}
	return ans;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mp[i][j];
		}
	}
	long long ans = 0;
	for (int i = 0; i < 26; ++i) {
		ans += work('a' + i);
	}
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}