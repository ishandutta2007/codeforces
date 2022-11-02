#include <bits/stdc++.h>
using namespace std;

#define N 1001001

const int inf = 2e9 + 7;

int n, x[N], h[N], ans;

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &x[i], &h[i]);
	int last = -inf;
	x[n+1] = inf;
	for (int i = 1; i <= n; i ++) {
		if (x[i] - h[i] > last) ans ++, last = x[i];
		else if (x[i] + h[i] < x[i+1]) ans ++, last = x[i] + h[i];
		else last = x[i];
	}
	printf("%d\n", ans);
	return 0;
}