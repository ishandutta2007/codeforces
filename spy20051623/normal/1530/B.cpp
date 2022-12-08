#include <bits/stdc++.h>

using namespace std;

int a[25][25];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	int f = 1;
	memset(a, 0, sizeof a);
	for (int i = 0; i < m; ++i) {
		a[0][i] = f;
		f ^= 1;
	}
	f = 1;
	for (int i = 2; i < n; ++i) {
		a[i][m - 1] = f;
		f ^= 1;
	}
	f = 1;
	for (int i = m - 3; i >= 0; --i) {
		a[n - 1][i] = f;
		f ^= 1;
	}
	f = 1;
	for (int i = n - 3; i > 1; --i) {
		a[i][0] = f;
		f ^= 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
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