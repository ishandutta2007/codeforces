#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

typedef long long lol;
typedef long double lod;

inline char readLetter() {
	char c = getchar();
	while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) { c = getchar(); }
	return c;
}
inline int read() {
	char c = getchar(); int n = 0, f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

const int maxInt = 2147483647;
const lol maxLongLong = 9223372036854775807LL;
const int maxN = 705;

int n, a[maxN];
bool f[maxN][maxN];
int x[maxN][maxN], y[maxN][maxN], s[maxN];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		x[i][i] = y[i][i] = true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (gcd(a[i], a[j]) > 1) {
				f[i][j] = true;
			}
		}
	}
	for (int len = 1; len <= n; len++) {
		for (int l = 1; l <= n; l++)
		{
			int r = l + len - 1;
			if (r > n) {
				break;
			}
			for (int k = l; k <= r; k++) {
				if (x[k][l] && y[k][r])
				{
					if (l == 1 && r == n)
					{
						printf("YES\n");
						return 0;
					}
					if (f[l - 1][k]) y[l - 1][r] = true;
					if (f[r + 1][k]) x[r + 1][l] = true;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}

// By Sooke.
// CF1025D Recovering BST.