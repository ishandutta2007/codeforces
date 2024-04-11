#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

void openFile() { freopen("mine.in", "r", stdin); freopen("mine.out", "w", stdout); }
void closeFile() { fclose(stdin); fclose(stdout); }

const int maxN = 1000005, p = 1000000007;

int n, f[2][2][2];
char str[maxN];

inline bool k(char c) { return str[n] == c; }
inline void m(int x, int a, int b) { if (f[x][a][b] > p) { f[x][a][b] -= p; } }
inline void q(int x) { m(x, 0, 0), m(x, 0, 1), m(x, 1, 0), m(x, 1, 1); }

int main() {
	for (str[++n] = getchar(); k('0') || k('1') || k('2') || k('*') || k('?'); str[++n] = getchar());
	n--, f[0][0][0] = f[0][0][1] = 1;
	for (int i = 1; i <= n; i++) {
		int x = i & 1, y = x ^ 1;
		memset(f[x], 0, sizeof(f[x]));
		if (str[i] == '0' || str[i] == '?') { f[x][0][0] += f[y][0][0]; } q(x);
		if (str[i] == '1' || str[i] == '?') { f[x][0][1] += f[y][0][0], f[x][0][0] += f[y][1][0]; } q(x);
		if (str[i] == '2' || str[i] == '?') { f[x][0][1] += f[y][1][0]; } q(x);
		if (str[i] == '*' || str[i] == '?') { f[x][1][0] += f[y][0][1] + f[y][1][1], f[x][1][1] += f[y][0][1] + f[y][1][1]; } q(x);
	}
	printf("%d\n", (f[n & 1][0][0] + f[n & 1][1][0]) % p);
	return 0;
}