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

#define MAXN 1005

int n;

struct Stc {
	int id, sum;
} S[MAXN];

bool cmp(Stc A, Stc B) {
	return A.sum == B.sum ? A.id < B.id : A.sum > B.sum;
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		int a = read(), b = read(), c = read(), d = read();
		S[i].id = i;
		S[i].sum = a + b + c + d;
	}
	std::sort(S + 1, S + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (S[i].id == 1) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}

// By Sooke.
// CF1017A The Rank.