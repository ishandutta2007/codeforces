#include <bits/stdc++.h>

using namespace std;

int a[1005][1005];
int b[1005][1005];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	int p[3] = {0, 0, 0}, q[3] = {0, 1, 2};
	getchar();
	while (m--) {
		char ch = getchar();
		if (ch == 'U')--p[q[0]];
		if (ch == 'D')++p[q[0]];
		if (ch == 'L')--p[q[1]];
		if (ch == 'R')++p[q[1]];
		if (ch == 'I')swap(q[1], q[2]);
		if (ch == 'C')swap(q[0], q[2]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int t[3] = {i, j, a[i][j] - 1};
			b[((t[q[0]] + p[q[0]]) % n + n) % n][((t[q[1]] + p[q[1]]) % n + n) % n] =
					((t[q[2]] + p[q[2]]) % n + n) % n + 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", b[i][j]);
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