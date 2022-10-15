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

#define MAXN 200005

int n;
lol ans = 0, sum1, sum3, a[MAXN];

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for (int i = 1, j = n + 1; i <= n; i++) {
		sum1 += a[i];
		while (i < j - 1 && sum3 + a[j - 1] <= sum1) {
			sum3 += a[j - 1];
			j--;
		}
		if (i >= j) {
			break;
		}
		if (sum1 == sum3) {
			ans = sum1;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}