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

int n, m;
string s;

int main() {
	n = read(), m = read();
	cin >> s;
	s = " " + s;
	for (int i = 1; i <= m; i++) {
		for (int j = 2; j <= n; j++) {
			if (s[j - 1] == 'B' && s[j] == 'G') {
				SWAP(s[j - 1], s[j]);
				j++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		putchar(s[i]);
	}
	printf("\n");
	return 0;
}

// By Sooke.
// CF266B Queue at the School.