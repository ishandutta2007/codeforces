#include <bits/stdc++.h>
using namespace std;

#define N 200010

int a[N], n, w;

int main() {
	scanf("%d %d", &n, &w);
	for (int i = 1; i <= 2 * n; i ++) scanf("%d", &a[i]);
	sort (a + 1, a + 2 * n + 1);
	long long x;
	x = min(w * 2ll, min(a[1] * 1ll * 6 * n, a[n+1] * 1ll * 3 * n));
	printf("%I64d", x / 2);
	if (x % 2) puts(".5");
	return 0;
}