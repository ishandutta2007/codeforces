#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Maxn 100005
#define Inf 2147483647

#define Swap(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

int n, lef, a[Maxn], pre[Maxn], suf[Maxn];
long long ans = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = n; i >= 1; i--) {
		if (suf[a[i]] == 0) {
			lef++;
		}
		suf[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		suf[a[i]]--;
		if (suf[a[i]] == 0) {
			lef--;
		}
		if (pre[a[i]] == 0) {
			ans += lef;
		}
		pre[a[i]]++;
	}
	printf("%I64d\n", ans);
	return 0;
}

// By Sooke.
// CF1004C Sonya and Robots.