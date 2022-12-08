#include <bits/stdc++.h>

using namespace std;
int s[3][200005];
int c[3][2];
int n;

void find(int &x, int &y, int &k) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			int p = (i + 1) % 3;
			if (c[i][j] >= n && c[p][j] >= n) {
				x = i;
				y = p;
				k = j;
				return;
			}
		}
	}
}

void print(int x, int y, int k) {
	int i = 0;
	int j = 0;
	while (i < n * 2 || j < n * 2) {
		while (s[x][i] != k && i < n * 2) {
			printf("%d", s[x][i]);
			++i;
		}
		while (s[y][j] != k && j < n * 2) {
			printf("%d", s[y][j]);
			++j;
		}
		if (i < n * 2 || j < n * 2) {
			printf("%d", k);
			++i;
			++j;
		}
	}
	printf("\n");
}

void solve() {
	scanf("%d", &n);
	memset(c, 0, sizeof c);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n * 2; ++j) {
			scanf("%1d", &s[i][j]);
			++c[i][s[i][j]];
		}
	}
	int x, y, k;
	find(x, y, k);
	print(x, y, k);
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