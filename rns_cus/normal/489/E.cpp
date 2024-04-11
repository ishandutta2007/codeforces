#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define inf 1e9
#define ep 1e-8

int n, L, x[N], b[N], prv[N];
double f[N];

bool ok(double mid) {
    for (int i = 1; i <= n; i ++) {
		f[i] = -inf;
		for (int j = 0; j < i; j ++) {
			if (f[i] < f[j] + mid * b[i] - sqrt(abs(x[i] - x[j] - L))) {
				f[i] = f[j] + mid * b[i] - sqrt(abs(x[i] - x[j] - L));
				prv[i] = j;
			}
		}
    }
    return f[n] >= 0;
}

void print(int x) {
	if (!x) return;
	print(prv[x]);
	printf("%d ", x);
}

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d %d", &n, &L);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &x[i], &b[i]);
	double st = 0, en = 1e3;
	while (en - st > ep) {
		double mid = (st + en) / 2;
		if (ok(mid)) en = mid;
		else st = mid;
	}
	print(n);
	return 0;
}