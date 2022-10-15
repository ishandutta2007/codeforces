#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

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

inline char letter() {
	char c = getchar();
	while (c < 'a' || c > 'z') {
		c = getchar();
	}
	return c;
}
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

#define MAXN 200005

lol ans, sl[MAXN], tl[MAXN];
int n, m, nxt[MAXN];
char sc[MAXN], tc[MAXN];

void init() {
	nxt[1] = nxt[2] = 1;
	for (int i = 3, j = 1; i <= m - 1; i++) {
		while ((tc[i] != tc[j + 1] || tl[i] != tl[j + 1]) && j > 1) {
			j = nxt[j];
		}
		if (tc[i] == tc[j + 1] && tl[i] == tl[j + 1]) {
			j++;
		}
		nxt[i] = j;
	}
}
void kmp() {
	for (int i = 2, j = 1; i < n; i++) {
		while ((sc[i] != tc[j + 1] || sl[i] != tl[j + 1]) && j > 1) {
			j = nxt[j];
		}
		if (sc[i] == tc[j + 1] && sl[i] == tl[j + 1]) {
			j++;
		}
		if (j == m - 1) {
			j = nxt[j];
			if (sc[i - m + 2] == tc[1] && sl[i - m + 2] >= tl[1] && sc[i + 1] == tc[m] && sl[i + 1] >= tl[m]) {
				ans++;	
			}
		}
	}
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		sl[i] = read(), sc[i] = letter();
		if (sc[i - 1] == sc[i]) {
			sl[i - 1] += sl[i];
			n--, i--;
		}
	}
	for (int i = 1; i <= m; i++) {
		tl[i] = read(), tc[i] = letter();
		if (tc[i - 1] == tc[i]) {
			tl[i - 1] += tl[i];
			m--, i--;
		}
	}
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			if (sc[i] == tc[1] && sl[i] >= tl[1]) {
				ans += sl[i] - tl[1] + 1;
			}
		}
	} else if (m == 2) {
		for (int i = 2; i <= n; i++) {
			if (sc[i - 1] == tc[1] && sl[i - 1] >= tl[1] && sc[i] == tc[2] && sl[i] >= tl[2]) {
				ans++;
			}
		}
	} else if (n < m) {
		ans = 0;
	} else {
		init();
		kmp();
	}
	printf("%I64d\n", ans);
	return 0;
}

// By Sooke.
// CF631D Messenger.