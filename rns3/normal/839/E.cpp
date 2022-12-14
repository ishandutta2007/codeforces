#include <bits/stdc++.h>
using namespace std;

#define N 42

#define P 101
typedef long long LL;

int rmh[P];

void prep() {
	for (int i = 0, j = 1; i < N; i ++, j = (j * 2) % P) rmh[j] = i;
}

int calc(LL x) {
	if (!x) return N;
	x = (x & (-x)) % P;
	return rmh[x];
}

int n, m;
LL g[N];

int func(LL cur, LL allo) {
	if (!allo) {
		int rlt = 0;
		for (LL u = cur & -cur; cur; cur -= u, u = cur & -cur) rlt ++;
		return rlt;
	}
    int ris = calc(allo);
    int rlt = 0;
    LL now = (~g[ris]) & allo;
    for (int u = 0; u < n; u ++) if ((1ll << u) & now) {
		rlt = max(rlt, func(cur | (1ll << u), allo & g[u]));
		allo ^= (1ll << u);
    }
    return rlt;
}

int main() {
	prep();
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) for (int j = 0, x; j < n; j ++) scanf("%d", &x), g[i] |= (1ll * x << j);
	int ans = func(0, (1ll << n) - 1);
	if (!ans) {
		puts("0");
		return 0;
	}
	printf("%.6lf\n", 0.5 * m * m * (ans - 1) / ans);
	return 0;
}