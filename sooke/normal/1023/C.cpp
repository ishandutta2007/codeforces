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

int n, m, v, stc[MAXN], pre[MAXN];
bool used[MAXN];
std::string s;

int main() {
	n = read(), m = read();
	std::cin >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') {
			stc[++v] = i;
		} else {
			pre[i] = stc[v--];
		}
	}
	m >>= 1;
	for (int i = 1; i <= n && m >= 1; i++) {
		if (s[i] == ')') {
			used[i] = used[pre[i]] = true;
			m--;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (used[i]) {
			printf("%c", s[i]);
		}
	}
	return 0;
}

// By Sooke.
// CF1023C Bracket Subsequence.