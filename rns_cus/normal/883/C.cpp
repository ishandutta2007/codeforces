#include <bits/stdc++.h>
using namespace std;

int a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3, a, b, c, d;

const int D = 1e7;

const long long INF = 1ll << 61;

long long calc(long long X, long long Y) {
	if (Y < 0) return INF;
	if (X <= 0) return 0;
	if (X * b1 <= Y) return 0;
	long long rlt = INF;
	d2 = X / a2;
	if (1ll * a2 * d2 * b2 + 1ll * b1 * (X % a2) <= Y) rlt = min(rlt, 1ll * d2 * c2);
	d2 ++;
	if (1ll * X * b2 <= Y) rlt = min(rlt, 1ll * d2 * c2);
	if (b1 > b2) {//puts("fsfs");
		d2 = (X * b1 - Y - 1) / (1ll * a2 * b1 - 1ll * a2 * b2);
		d2 ++;
		d1 = X - 1ll * a2 * d2;
		if (d1 >= 0) rlt = min(rlt, 1ll * d2 * c2);
	}
	return rlt;
}

int main() {
	//freopen("r.in", "r", stdin);
	a1 = 1, c1 = 0;
	scanf("%d %d %d %d %d %d %d %d %d", &a, &b, &b1, &a2, &b2, &c2, &a3, &b3, &c3);
	if (b3 > b2) swap(a3, a2), swap(b3, b2), swap(c3, c2);
	b2 = min(b2, b1);
	b3 = min(b3, b1);
	if (1ll * b3 * a > b) {
		puts("-1");
		return 0;
	}

	long long ans = INF;
	for (d3 = 0; d3 <= D; d3 ++) {
		ans = min(ans, 1ll * d3 * c3 + calc(a - 1ll * a3 * d3, b - 1ll * min(1ll * a3 * d3, 1ll * a) * b3));
		if (a < 1ll * a3 * d3) break;
	}
	printf("%I64d\n", ans);

	return 0;
}