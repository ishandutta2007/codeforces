#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

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

#define MAXN 120005

map<int, int> M;
int n, ans, a[MAXN];

inline bool check(int d) {
	for (int i = 1; i <= 30; i++) {
		int k = M[(1 << i) - d];
		if (k > 1 || ((1 << i) - d != d && k == 1)) {
			return false;	
		}
	}
	return true;
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		M[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		if (check(a[i])) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}

// By Sooke.