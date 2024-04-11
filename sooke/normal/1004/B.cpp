#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Inf 2147483647

#define Swap(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d", i % 2);
	}
	printf("\n");
	return 0;
}

// By Sooke.
// CF1004B Sonya and Exhibition.