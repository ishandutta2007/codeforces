#include <bits/stdc++.h>
using namespace std;

#define N 202020

int a[N], n, m, prv[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	a[0] = -1;
	for (int i = 1; i <= n; i ++) prv[i] = (a[i] != a[i-1]) ? (i - 1) : (prv[i-1]);
	for (int i = 1, le, ri, x; i <= m; i ++) {
		scanf("%d %d %d", &le, &ri, &x);
		if (a[ri] != x) printf("%d\n", ri);
		else if (prv[ri] >= le) printf("%d\n", prv[ri]);
		else puts("-1");
	}

	return 0;
}