#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100000;
int a[maxN];
int n;
int p[maxN];

int presented[20 * maxN];

int findSet(int x) {
	if (p[x] == x) {
		return x;
	}
	return p[x] = findSet(p[x]);
}

void merge(int x, int y) {
	x = findSet(x);
	y = findSet(y);
	if (rand() % 2) {
		p[x] = y;
	} else {
		p[y] = x;
	}
}

inline int gcd(int x, int y) {
	int b1 = x;
	int b2 = y;
	while (b2) {
		int q = b1 / b2;
		b1 -= q * b2;
		swap(b1, b2);
	}
	return b1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		p[i] = i;
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;
	memset(presented, -1, sizeof(presented));
	for (int i = 0; i < n; ++i) {
		presented[a[i]] = i;
	}

	for (int n = 1; n * n <= 10000000; ++n) {
		for (int m = n + 1; m * m + n * n <= 20000000; m += 2) {
			if (gcd(n, m) != 1) {
				continue;
			}
			int x = m * m - n * n;
			int y = 2 * m * n;
			int z = m * m + n * n;
			if (x == 4 && y == 3 && z == 5) {
				int t = 0;
			}
			if (presented[x] != -1 && presented[y] != -1) {
				merge(presented[x], presented[y]);
			}
			if (presented[x] != -1 && presented[z] != -1) {
				merge(presented[x], presented[z]);
			}
			if (presented[y] != -1 && presented[z] != -1) {
				merge(presented[y], presented[z]);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		p[i] = findSet(i);
	}
	sort(p, p + n);
	int res = unique(p, p + n) - p;
	printf("%d\n", res);

	return 0;
}