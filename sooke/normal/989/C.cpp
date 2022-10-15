#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
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

#define MAXN 51

int a, b, c, d;
char f[MAXN][MAXN];

int main() {
	a = read(), b = read(), c = read(), d = read();
	printf("48 50\n");
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 50; j++) {
			f[i][j] = 'A';
		}
	}
	for (int i = 13; i <= 24; i++) {
		for (int j = 1; j <= 50; j++) {
			f[i][j] = 'B';
		}
	}
	for (int i = 25; i <= 36; i++) {
		for (int j = 1; j <= 50; j++) {
			f[i][j] = 'C';
		}
	}
	for (int i = 37; i <= 48; i++) {
		for (int j = 1; j <= 50; j++) {
			f[i][j] = 'D';
		}
	}
	a--, b--, c--, d--;
	for (int i = 2; i <= 11; i++) {
		for (int j = 2; j <= 49; j++) {
			if (d > 0 && (i + j) % 3 == 0) {
				f[i][j] = 'D';
				d--;
			}
		}
	}
	for (int i = 14; i <= 23; i++) {
		for (int j = 2; j <= 49; j++) {
			if (a > 0 && (i + j) % 3 == 0) {
				f[i][j] = 'A';
				a--;
			}
		}
	}
	for (int i = 26; i <= 35; i++) {
		for (int j = 2; j <= 49; j++) {
			if (b > 0 && (i + j) % 3 == 0) {
				f[i][j] = 'B';
				b--;
			}
		}
	}
	for (int i = 38; i <= 47; i++) {
		for (int j = 2; j <= 49; j++) {
			if (c > 0 && (i + j) % 3 == 0) {
				f[i][j] = 'C';
				c--;
			}
		}
	}
	for (int i = 1; i <= 48; i++) {
		for (int j = 1; j <= 50; j++) {
			putchar(f[i][j]);
		}
		putchar('\n');
	}
	return 0;
}

// By Sooke.
// CF989C A Mist of Florescence.