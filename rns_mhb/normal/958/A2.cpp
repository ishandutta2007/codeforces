#include <bits/stdc++.h>
using namespace std;

#define N 2020
#define M 202

const int mod = 1e9 + 7;
const int seed = 917;

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * a * rlt % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return rlt;
}

int calc_hash(char *s, int m) {
	int rlt = 0;
	for (int i = 0; i < m; i ++) rlt = (1ll * rlt * seed + s[i]) % mod;
	return rlt;
}

char s[N][M], t[M][N];
int a[N], b[M][N];

int n, m;

bool check(int x, int y) {
	for (int i = 0; i < m; i ++) for (int j = 0; j < m; j ++) if (s[i+x][j] != t[i][j+y]) return 0;
	return 1;
}

int con;

int h[N];

int c[N];

void prepare(int *p, int m) {
	for (int i = 1, j = 0; i < m; i ++) {
		while (j && p[i] != p[j]) j = h[j-1];
		if (p[i] == p[j]) j ++;
		h[i] = j;
	}
}

void kmp_matching(int *t, int *p, int *f, int n, int m) {
	for (int i = 0, j = 0; i < n; i ++) {
		while (j && t[i] != p[j]) j = h[j-1];
		if (t[i] == p[j]) j ++;
		f[i] = j;
		if (j == m) j = h[j-1];
	}
}

int f[N];

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; i ++) gets(s[i]);
	for (int i = 0; i < m; i ++) gets(t[i]);
	for (int i = 0; i < n; i ++) a[i] = calc_hash(s[i], m);
	con = expmod(seed, m);

	for (int i = 0; i < m; i ++) {
		b[i][0] = calc_hash(t[i], m);
		for (int j = 1; j <= n - m; j ++) {
			b[i][j] = (1ll * b[i][j-1] * seed - 1ll * con * t[i][j-1] + t[i][j-1+m]) % mod;
			b[i][j] = (b[i][j] + mod) % mod;
		}
	}

	for (int jj = 0; jj <= n - m; jj ++) {
		for (int i = 0; i < m; i ++) c[i] = b[i][jj];
		prepare(c, m);
		kmp_matching(a, c, f, n, m);
		for (int i = 0; i < n; i ++) if (f[i] == m) {
			if (check(i - m + 1, jj)) {
				printf("%d %d\n", i - m + 2, jj + 1);
				return 0;
			}
		}
	}

	return 0;
}