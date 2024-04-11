#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Inf 2147483647
#define Maxn 5001

#define Swap(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

int n, m, a[Maxn], pre[Maxn];
double ans = -1.0;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i - m + 1; j >= 1; j--) {
			ans = Max(ans, (double)(pre[i] - pre[j - 1]) / (i - j + 1));
		}
	}
	printf("%.7lf\n", ans);
	return 0;
}

// By Sooke.
// CF1003C Intense Heat.