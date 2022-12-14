#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define D 1000010

const int INF = 1e9 + 1;

int n, a, b, x[N], to[D], y[N], m;

int main() {
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++) scanf("%d", &y[i]);
	sort (y + 1, y + m + 1);
	int n = 1;
	x[1] = y[1];
	for (int i = 2; i <= m; i ++) {
		if (y[i] != y[i-1]) x[++n] = y[i];
	}
	scanf("%d %d", &a, &b);
	int d = a - b;
	to[1] = 0;
	for (int i = 1; i < D; i ++) to[i] = i - 1;
    for (int i = 1; i <= n; i ++) {
		for (int j = (b + x[i] - 1) / x[i] * x[i]; j <= a; j += x[i]) {
			int tag = min(d, j-b+x[i]-1);
			to[tag] = min(to[tag], j - b);
		}
    }
    int now = d, tto = to[d], nxt, ans = 0;
    while (now) {
        nxt = tto;
		for (int i = now - 1; i >= nxt; i --) tto = min(tto, to[i]);
        now = nxt;
        ans ++;
    }
    printf("%d\n", ans);
	return 0;
}