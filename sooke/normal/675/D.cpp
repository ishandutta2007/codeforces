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

#define INF 2147483647

map<int, int> M;
int n, t;

int main() {
	n = read(), t = read();
	M[t] = M[INF] = t;
	for (int i = 2; i <= n; i++) {
		t = read();
		map<int, int>::iterator ite = M.lower_bound(t);
		printf("%d ", (*ite).second);
		M[t] = (*ite).second = t;
	}
	return 0;
}

// By Sooke.
// CF675D Tree Construction.