#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, s, va[55], vb[55], a[55]; vector<int> b[55]; map<int, vector<int> > d; long long dp[55][55][5005];
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> va[i];
	for (int i = 0; i < n; ++i) {
		cin >> vb[i];
		d[va[i]].push_back(vb[i]);
		s += vb[i];
	}
	m = d.size();
	int cur = m;
	for (pair<int, vector<int> > i : d) {
		--cur;
		a[cur] = i.first;
		b[cur] = i.second;
		sort(b[cur].begin(), b[cur].end());
	}
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k <= s; ++k) {
				dp[i][j][k] = 1LL << 60;
			}
		}
	}
	dp[0][0][0] = 0;
	int cs = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= cs; ++j) {
			for (int k = 0; k <= s; ++k) {
				if (dp[i][j][k] == (1LL << 60)) continue;
				for (int l = 0; l <= b[i].size() && l <= j; ++l) {
					int sum = 0;
					for (int x = l; x < b[i].size(); ++x) sum += b[i][x];
					int nj = j - l + (b[i].size() - l);
					dp[i + 1][nj][k + sum] = min(dp[i + 1][nj][k + sum], dp[i][j][k] + 1LL * a[i] * (b[i].size() - l));
				}
			}
		}
		cs += b[i].size();
	}
	long long ret = 1LL << 60;
	for (int i = 0; i <= n; ++i) {
		for (int j = 1; j <= s; ++j) {
			if (dp[m][i][j] != (1LL << 60)) {
				ret = min(ret, (dp[m][i][j] * 1000 + j - 1) / j);
			}
		}
	}
	cout << ret << '\n';
	return 0;
}