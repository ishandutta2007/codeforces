#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Maxn 105
#define Inf 2147483647

#define Swap(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

int n, m, d, ans, a[Maxn];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	ans = 2;
	for (int i = 2; i <= n; i++) {
		d = a[i] - a[i - 1];
		if (d == m * 2) {
			ans++;
		} else if(d > m * 2) {
			ans += 2;
		}
	}
	printf("%d\n", ans);
	return 0;
}

// By Sooke.
// CF1004A Sonya and Hotels.