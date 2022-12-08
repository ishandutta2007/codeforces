#include <bits/stdc++.h>

using namespace std;

struct op {
	int a, b, c, d, e, f;

	void print() const {
		printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
	}

	op(int aa, int bb, int cc, int dd, int ee, int ff) {
		a = aa, b = bb, c = cc, d = dd, e = ee, f = ff;
	}
};

char s[105][105];
int a[105][105];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<op> v;
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			a[i][j] = s[i][j] - '0';
		}
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j]) {
				if (a[i][j + 1]) {
					v.emplace_back(i, j, i, j + 1, i + 1, j);
					a[i][j] ^= 1, a[i][j + 1] ^= 1, a[i + 1][j] ^= 1;
				} else if (j < m) {
					v.emplace_back(i, j, i + 1, j, i + 1, j + 1);
					a[i][j] ^= 1, a[i + 1][j] ^= 1, a[i + 1][j + 1] ^= 1;
				} else {
					v.emplace_back(i, j, i + 1, j, i + 1, j - 1);
					a[i][j] ^= 1, a[i + 1][j] ^= 1, a[i + 1][j - 1] ^= 1;
				}
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (a[n][i]) {
			if (a[n][i + 1] && a[n][i + 2]) {
				v.emplace_back(n, i, n, i + 1, n - 1, i + 1);
				v.emplace_back(n, i + 1, n - 1, i + 1, n - 1, i + 2);
				v.emplace_back(n, i + 1, n, i + 2, n - 1, i + 2);
				a[n][i] ^= 1, a[n][i + 1] ^= 1, a[n][i + 2] ^= 1;
			} else if (a[n][i + 1]) {
				v.emplace_back(n, i, n - 1, i, n - 1, i + 1);
				v.emplace_back(n, i + 1, n - 1, i, n - 1, i + 1);
				a[n][i] ^= 1, a[n][i + 1] ^= 1;
			} else if (a[n][i + 2]) {
				v.emplace_back(n, i, n, i + 1, n - 1, i + 1);
				v.emplace_back(n, i + 2, n, i + 1, n - 1, i + 1);
				a[n][i] ^= 1, a[n][i + 2] ^= 1;
			} else if (i < m) {
				v.emplace_back(n, i, n - 1, i, n - 1, i + 1);
				v.emplace_back(n, i, n - 1, i, n, i + 1);
				v.emplace_back(n, i, n, i + 1, n - 1, i + 1);
				a[n][i] ^= 1;
			} else {
				v.emplace_back(n, i, n - 1, i, n - 1, i - 1);
				v.emplace_back(n, i, n - 1, i, n, i - 1);
				v.emplace_back(n, i, n, i - 1, n - 1, i - 1);
				a[n][i] ^= 1;
			}
		}
	}
	printf("%d\n", v.size());
	for (auto &i : v) i.print();
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}