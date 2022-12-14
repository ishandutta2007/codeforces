#include <cstdio>

using namespace std;

int read() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

const int MAXN = 7070;
int n, k[2], s[2][MAXN], f[2][MAXN], deg[2][MAXN];

void dfs(int x, int y, int v) {
	if (f[x][y]) return;
	f[x][y] = v;
	if (v == 1) {
		for (int i = 1; i <= k[!x]; i ++) {
			dfs(!x, (y + s[!x][i]) % n, 2);
		}
	}
	else {
		for (int i = 1; i <= k[!x]; i ++) {
			if (!--deg[!x][(y + s[!x][i]) % n]) {
				dfs(!x, (y + s[!x][i]) % n, 1);
			}
		}
	}
}

int main() {
	n = read();
	for (int o = 0; o < 2; o ++) {
		k[o] = read();
		for (int i = 1; i <= k[o]; i ++) s[o][i] = read();
		for (int i = 0; i < n; i ++) deg[o][i] = k[o];
	}
	f[0][0] = f[1][0] = 1; // lose 1 win 2
	for (int x = 0; x < 2; x ++) {
		for (int i = 1; i <= k[x]; i ++) {
			dfs(x, s[x][i], 2);
		}
	}
	for (int x = 0; x < 2; x ++) {
		for (int i = n - 1; i; i --) {
			if (f[x][i] == 2) printf("Win ");
			else if (f[x][i] == 1) printf("Lose ");
			else printf("Loop ");
		}
		puts("");
	}
	return 0;
}