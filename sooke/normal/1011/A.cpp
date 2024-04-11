#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAXINT 2147483647
#define MAXLOL 9223372036854775807
#define INF MAXINT
#define lol long long

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

#define MAXN 101

int n, m, ans = INF, a[MAXN], f[MAXN][MAXN];
string s;

int main() {
	n = read(), m = read();
	cin >> s;
	for (int i = 1; i <= n; i++) {
		a[i] = s[i - 1] - 'a' + 1;
	}
	sort(a + 1, a + n + 1);
	memset(f, 127, sizeof(f));
	for (int i = 1; i <= n; i++) {
		f[i][1] = a[i];
		for (int j = 1; j < i; j++) {
			for (int k = 2; k <= m; k++) {
				if (a[j] + 2 <= a[i]) {
					f[i][k] = MIN(f[i][k], f[j][k - 1] + a[i]);
				}
			}
		}
		ans = MIN(ans, f[i][m]);
	}
	if (ans > INF / 2) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}

// By Sooke.
// CF1011A Stages.