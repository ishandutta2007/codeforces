#include <bits/stdc++.h>

using namespace std;

int g[8][3][2] = {
		{
				{0, 1},
				{0, 0},
				{0, 1}
		},
		{
				{1, 0},
				{0, 0},
				{1, 0}
		},
		{
				{1, 0},
				{1, 1},
				{1, 0}
		},
		{
				{0, 1},
				{1, 1},
				{0, 1}
		},
		{
				{1, 0},
				{0, 0},
				{0, 1}
		},
		{
				{0, 1},
				{0, 0},
				{1, 0}
		},
		{
				{0, 1},
				{1, 1},
				{1, 0}
		},
		{
				{1, 0},
				{1, 1},
				{0, 1}
		}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	if (n >= 4 && m >= 4) {
		cout << "-1\n";
		return 0;
	}
	if (n == 1 || m == 1) {
		cout << "0\n";
		return 0;
	}
	vector<vector<int>> a;
	if (n == 2 || n == 3) {
		a = vector<vector<int>>(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < m; ++j) {
				a[i][j] = s[j] - '0';
			}
		}
	} else {
		a = vector<vector<int>>(m, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < m; ++j) {
				a[j][i] = s[j] - '0';
			}
		}
		swap(n, m);
	}
	int ans = 1e9;
	for (auto &i: g) {
		int sum = 0;
		for (int j = 0; j < m; ++j) {
			int tmp = 0;
			for (int k = 0; k < n; ++k) {
				tmp += a[k][j] != i[k][j & 1];
			}
			tmp = min(tmp, n - tmp);
			sum += tmp;
		}
		ans = min(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}