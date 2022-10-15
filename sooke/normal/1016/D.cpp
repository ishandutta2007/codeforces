#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using std::string;

#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAXINT 2147483647
#define MAXLOL 9223372036854775807LL
#define INF MAXINT
#define lol long long
#define lod long double

inline int read() {
	char c = getchar();
	int n = 0, f = 0;
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = 1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar();
	}
	return f ? -n : n;
}

#define MAXN 1005

lol f[MAXN][MAXN], a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int n, m;
bool flag;

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for (int i = 1; i <= m; i++) {
		b[i] = read();
	}
	for (int i = 0; i <= 31; i++) {
		for (int j = 1; j <= n; j++) {
			c[j] = (a[j] & (1 << i));
		}
		for (int j = 1; j <= m; j++) {
			d[j] = (b[j] & (1 << i));	
		}
		for (int j = 1; j <= n; j++) {
			int cnt = 0;
			for (int k = 1; k <= m; k++) {
				if (d[k]) {
					cnt++;		
				}
			}
			if (cnt % 2 != 0) {
				cnt--;
			}
			if (c[j]) {
				cnt++;
			}
			for (int k = 1; k <= m; k++) {
				if (d[k] && cnt) {
					cnt--;
					d[k] = 0;
					f[j][k] ^= (1 << i);
				}
			}
			if (cnt) {
				d[1] = 1 - d[1];
				f[j][1] ^= (1 << i);
			}
		}
		flag = true;
		for (int j = 1; j <= m; j++) {
			if (d[j]) {
				flag = false;
			}
		}
		if (!flag) {
			std::cout << "NO" << std::endl;
			return 0;
		}
	}
	std::cout << "YES" << std::endl;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			printf("%d ", (int)f[i][j]);
		}
		printf("\n");
	}
	return 0;
}

// By WXW.
// CF1016D Vasya And The Matrix.