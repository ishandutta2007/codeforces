#include <bits/stdc++.h>

using namespace std;

int a[205][205][205];

struct dp {
	int pos;
	int op;
	int num;
	int res;
};

int main() {
//	freopen("in.txt", "r", stdin);
	int n, k;
	string s, t;
	scanf("%d%d", &n, &k);
	cin >> s >> t;
	if (t[0] == t[1]) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == t[0])
				++cnt;
		}
		cnt = min(n, cnt + k);
		printf("%d\n", cnt * (cnt - 1) / 2);
		return 0;
	}
	memset(a, -1, sizeof a);
	a[0][0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int l = 0; l < n; ++l) {
				if (a[i][j][l] >= 0) {
					if (s[i] == t[0]) {
						a[i + 1][j][l + 1] = max(a[i + 1][j][l + 1], a[i][j][l]);
						if (j < k)
							a[i + 1][j + 1][l] = max(a[i + 1][j + 1][l], a[i][j][l] + l);
					} else if (s[i] == t[1]) {
						a[i + 1][j][l] = max(a[i + 1][j][l], a[i][j][l] + l);
						if (j < k)
							a[i + 1][j + 1][l + 1] = max(a[i + 1][j + 1][l + 1], a[i][j][l]);
					} else {
						a[i + 1][j][l] = max(a[i + 1][j][l], a[i][j][l]);
						if (j < k) {
							a[i + 1][j + 1][l + 1] = max(a[i + 1][j + 1][l + 1], a[i][j][l]);
							a[i + 1][j + 1][l] = max(a[i + 1][j + 1][l], a[i][j][l] + l);
						}
					}
				}
			}
		}
	}
	int maxm = -1;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			maxm = max(maxm, a[n][i][j]);
		}
	}
	printf("%d\n", maxm);
	return 0;
}