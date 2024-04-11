#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

void input(int &x) {
	x = 0;
	char c = getchar();
	while(c <= 32) c = getchar();
	while(c > 32) x = x * 10 + (c ^ 48), c = getchar();
}

#define N 20002
#define B 151

int n, m, p, x, y;
int a[N], b[N];
int tmp[2][N], id[B + 10], cnt;
int f[B + 10][N], g[B + 10][N], I, J, C;
char s[N * 2];

inline int calc(int i, int j) { return (a[i] + b[j]) % p; }

void run() {
	for(int j = m - 2; j >= 0; j --) tmp[0][j] = tmp[0][j + 1] + calc(n - 1, j + 1);
	for(int j = 0; j < m; j ++) g[0][j] = tmp[0][j];
	id[cnt ++] = n - 1;
	I = 0;
	for(int i = n - 2; i >= 0; i --) {
		J = I; I = 1 - I;
		tmp[I][m - 1] = tmp[J][m - 1] + calc(i + 1, m - 1);
		for(int j = m - 2; j >= 0; j --) {
			tmp[I][j] = max(tmp[J][j] + calc(i + 1, j), tmp[I][j + 1] + calc(i, j + 1));
		}
		if(i % B == 0) {
			for(int j = 0; j < m; j ++) g[cnt][j] = tmp[I][j];
			id[cnt ++] = i;
		}
	}
	printf("%d\n", tmp[I][0] + calc(0, 0));
	for(int k = cnt - 2; k >= 0; k --) {
		int lo = id[k + 1], hi = id[k];
		for(int j = 0; j < m; j ++) f[0][j] = g[k][j];
		for(int j = 0; j < m; j ++) f[hi - lo][j] = g[k + 1][j];
		for(int i = hi - 1; i > lo; i --) {
			f[hi - i][m - 1] = f[hi - i - 1][m - 1] + calc(i + 1, m - 1);
			for(int j = m - 2; j >= 0; j --) {
				f[hi - i][j] = max(f[hi - i][j + 1] + calc(i, j + 1), f[hi - i- 1][j] + calc(i + 1, j));
			}
		}
		while(x < hi) {
			if(y < m - 1 && f[hi - x][y] == f[hi - x][y + 1] + calc(x, y + 1)) {
				y ++;
				s[C ++] = 'S';
			}
			else {
				x ++;
				s[C ++] = 'C';
			}
		}
	}
	while(y < m - 1) {
		s[C ++] = 'S'; y ++;
	}
	s[C] = 0;
	puts(s);
}

int main() {
	input(n); input(m); input(p);
	for(int i = 0; i < n; i ++) input(a[i]);
	for(int i = 0; i < m; i ++) input(b[i]);
	run();
	return 0;
}