#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Maxn 200005
#define Inf 2147483647

#define Swap(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

int n, m, ans, a[Maxn], b[33], c[33], pri[33];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int t = 0;
		while (a[i] > 1) {
			a[i] >>= 1;
			t++;
		}
		pri[t + 1]++;
	}
	for (int i = 1; i <= m; i++) {
		int t;
		scanf("%d", &t);
		for (int j = 1; j <= 31; j++) {
			if ((1 << j - 1) & t) {
				b[j] = 1;
			} else {
				b[j] = 0;
			}
		}
		memcpy(c, pri, sizeof(c));
		ans = 0;
		b[0] = 0;
		for (int j = 31; j >= 1; j--) {
			if (b[j] == 0) {
				continue;
			} else {
				if (c[j] < b[j]) {
					ans += c[j];
					b[j] -= c[j];
					b[j - 1] += b[j] * 2;
				} else {
					ans += b[j];
				}
			}
		}
		if (b[0] != 0) {
			ans = -1;
		}
		printf("%d\n", ans);
	}
	return 0;
}

// By Sooke.
// CF1003D Coins and Queries.