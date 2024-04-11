// AC

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Inf 2147483647
#define Maxn 101

#define Swap(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

int n, ans, cnt[Maxn];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t, cnt[t]++;
	}
	for (int i = 1; i <= 100; i++) {
		ans = Max(ans, cnt[i]);
	}
	printf("%d\n", ans);
	return 0;
}

// By Sooke.
// CF1003A Polycarp's Pockets.