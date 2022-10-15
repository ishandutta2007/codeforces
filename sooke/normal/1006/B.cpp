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

#define MAXN 2005

int n, m;

struct Num {
	int n, i;
} S[MAXN];

bool cmp(Num A, Num B) {
	return A.n > B.n;
}

int a[MAXN];

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		S[i].i = i;
		S[i].n = read();
	}
	sort(S + 1, S + n + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		a[i] = S[i].i;
		ans += S[i].n;
	}
	sort(a + 1, a + m + 1);
	printf("%d\n", ans);
	a[m] = n;
	for (int i = 1; i <= m; i++) {
		printf("%d ", a[i] - a[i - 1]);
	}
	return 0;
}