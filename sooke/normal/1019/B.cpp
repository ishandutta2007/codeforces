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

#define MAXN 100005

int n, a[MAXN];

int query(int u) {
	int v = (u + n / 2 - 1) % n + 1;
	if (a[u] == -1) {
		std::cout << "? " << u << std::endl;
		std::cin >> a[u];
		fflush(stdout);
	}
	if (a[v] == -1) {
		std::cout << "? " << v << std::endl;
		std::cin >> a[v];
	}
	return a[v] - a[u];
}

void dfs(int l, int r) {
	int x = query(l), y = query(r);
	if (x == 0) {
		std::cout << "! " << l << std::endl;
		exit(0);
	}
	if (y == 0) {
		std::cout << "! " << r << std::endl;
		exit(0);
	}
	int mid = l + r >> 1, z = query(mid);
	if (y == 0) {
		std::cout << "! " << mid << std::endl;
		exit(0);
	}
	if ((x < 0 && z > 0) || (x > 0 && z < 0)) {
		dfs(l, mid);
	} else {
		dfs(mid, r);
	}
}

int main() {
	std::cin >> n;
	if (n % 4 == 2) {
		std::cout << "! -1\n";
		return 0;
	}
	memset(a, -1, sizeof(a));
	dfs(1, n / 2 + 1);
	return 0;
}

// By Sooke.
// CF1019B The hat.