#include <bits/stdc++.h>
using namespace std;
#define N 101010

char s[N];
int q, n;
int a[11][10][4][N];

int f(char c) {
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	return 3;
}

void update(int x, int c, int val) {
	for (int i = 1; i <= 10; i ++) {
		for (int k = x; k <= n; k += k & -k) a[i][x%i][c][k] += val;
	}
}

int query(int x, int y , int z, int i) {
	int cnt = 0;
	for (; i; i -= i & -i) cnt += a[x][y][z][i];
	return cnt;
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i ++) update(i, f(s[i]), 1);
	scanf("%d", &q);
	while (q --) {
		int id;
		scanf("%d", &id);
		if (id == 1) {
			int x;
			char c[2];
			scanf("%d %s", &x, c);
			if (s[x] != c[0]) {

				update(x, f(s[x]), -1);
				update(x, f(c[0]), 1);
				s[x] = c[0];

			}
		}
		else {
			int l, r;
			char e[11];
			scanf("%d%d%s", &l, &r, &e);
			int m = strlen(e);
			int cnt = 0;
			for (int i = 0; i < m; i ++) cnt += query(m, (l + i) % m, f(e[i]), r) - query(m, (l + i) % m, f(e[i]), l - 1);
			printf("%d\n", cnt);
		}
	}
}