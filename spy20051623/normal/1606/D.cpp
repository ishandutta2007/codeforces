#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	vector<vector<int>> lmx(n, vector<int>(m));
	vector<vector<int>> lmn(n, vector<int>(m));
	vector<vector<int>> rmx(n, vector<int>(m));
	vector<vector<int>> rmn(n, vector<int>(m));
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
		v[i] = i;
	}
	sort(v.begin(), v.end(), [&](int x, int y) { return a[x][0] == a[y][0] ? x < y : a[x][0] < a[y][0]; });
	for (int i = 0; i < n; ++i) {
		lmx[i][0] = lmn[i][0] = a[i][0];
		for (int j = 1; j < m - 1; ++j) {
			lmx[i][j] = max(lmx[i][j - 1], a[i][j]);
			lmn[i][j] = min(lmn[i][j - 1], a[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		rmx[i][m - 1] = rmn[i][m - 1] = a[i][m - 1];
		for (int j = m - 2; j > 0; --j) {
			rmx[i][j] = max(rmx[i][j + 1], a[i][j]);
			rmn[i][j] = min(rmn[i][j + 1], a[i][j]);
		}
	}
	for (int i = 0; i < m - 1; ++i) {
		string s(n, 'R');
		vector<int> llmx(n);
		vector<int> llmn(n);
		vector<int> lrmx(n);
		vector<int> lrmn(n);
		vector<int> rlmx(n);
		vector<int> rlmn(n);
		vector<int> rrmx(n);
		vector<int> rrmn(n);
		llmx[0] = lmx[v[0]][i];
		llmn[0] = lmn[v[0]][i];
		rlmx[0] = rmx[v[0]][i + 1];
		rlmn[0] = rmn[v[0]][i + 1];
		for (int j = 1; j < n - 1; ++j) {
			llmx[j] = max(llmx[j - 1], lmx[v[j]][i]);
			llmn[j] = min(llmn[j - 1], lmn[v[j]][i]);
			rlmx[j] = max(rlmx[j - 1], rmx[v[j]][i + 1]);
			rlmn[j] = min(rlmn[j - 1], rmn[v[j]][i + 1]);
		}
		lrmx[n - 1] = lmx[v[n - 1]][i];
		lrmn[n - 1] = lmn[v[n - 1]][i];
		rrmx[n - 1] = rmx[v[n - 1]][i + 1];
		rrmn[n - 1] = rmn[v[n - 1]][i + 1];
		for (int j = n - 2; j > 0; --j) {
			lrmx[j] = max(lrmx[j + 1], lmx[v[j]][i]);
			lrmn[j] = min(lrmn[j + 1], lmn[v[j]][i]);
			rrmx[j] = max(rrmx[j + 1], rmx[v[j]][i + 1]);
			rrmn[j] = min(rrmn[j + 1], rmn[v[j]][i + 1]);
		}
		for (int j = 0; j < n - 1; ++j) {
			s[v[j]] = 'B';
			if (llmx[j] < lrmn[j + 1] && rlmn[j] > rrmx[j + 1]) {
				cout << "YES\n" << s << ' ' << i + 1 << '\n';
				return;
			}
		}
	}
	cout << "NO\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}