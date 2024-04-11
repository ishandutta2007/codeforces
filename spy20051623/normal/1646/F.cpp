#include <bits/stdc++.h>

using namespace std;
int n;
int a[105][105], c[105][105], s[105];

int lst(int x) { return x == 0 ? n - 1 : x - 1; }

int nxt(int x) { return x == n - 1 ? 0 : x + 1; }

int check() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (c[i][j] >= 2) return i;
		}
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			--a[i][j];
			++c[i][a[i][j]];
		}
	}
	vector<vector<int>> ans;
	int p;
	while ((p = check()) >= 0) {
		for (int i = p;; i = nxt(i)) {
			s[i] = i;
			for (int j = 0; j < n; ++j) {
				if (c[i][j] >= 2) {
					s[i] = j;
					break;
				}
			}
			--c[i][s[i]];
			++c[nxt(i)][s[i]];
			if (i == lst(p)) break;
		}
		vector<int> v;
		for (int i = 0; i < n; ++i) {
			v.push_back(s[i] + 1);
		}
		ans.push_back(v);
	}
	for (int i = 1; i < n; ++i) {
		for (int j = i; j; j = lst(j)) {
			vector<int> v;
			for (int k = j;; k = nxt(k)) {
				v.push_back(k + 1);
				if (k == lst(j)) break;
			}
			ans.push_back(v);
		}
	}
	cout << ans.size() << '\n';
	for (auto &i: ans) {
		for (int j: i) cout << j << ' ';
		cout << '\n';
	}
	return 0;
}