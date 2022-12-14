#include <bits/stdc++.h>
using namespace std;

const long double INF = 2e16;
const long double ep = 1e-10;

#define N 101010

int n, p;
int a[N], b[N];

bool ok(long double t) {
	long double res = t * p;
	for (int i = 1; i <= n; i ++) res -= max((long double)0.0, a[i] * t - b[i]);
	return res >= 0;
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d", &n, &p);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &a[i], &b[i]);
	long double st = 0, en = INF, mid;
	int step = 0;
	while (en - st > ep && step < 200) {
		mid = (en + st) / 2;
		if (ok(mid)) st = mid;
		else en = mid;
		step ++;
	}
	if (en >= INF / 2) puts("-1");
	else printf("%.7lf\n", (double)st);

	return 0;
}