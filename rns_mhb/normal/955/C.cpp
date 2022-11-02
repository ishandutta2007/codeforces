#include <bits/stdc++.h>
using namespace std;

const long long INF = 1ll << 60;

long long a[4030303];
int e;

void prep() {
	a[++e] = 1;
	for (int i = 2; i <= 1e6; i ++) {
		long long now = 1ll * i * i * i;
		a[++e] = now;
		while (INF / i >= now) {
			now *= i;
			a[++e] = now;
		}
	}
	sort(a + 1, a + e + 1);
	e = unique(a + 1, a + e + 1) - a - 1;
	int ee = 0;
	for (int i = 1; i <= e; i ++) {
		long long now = sqrt((long double)a[i]);
		if (now * now != a[i]) a[++ee] = a[i];
	}
	e = ee;
	a[++e] = INF;
}

int func(long long x) {
	int i = lower_bound(a + 1, a + e + 1, x + 1) - a;
	return i + (int)(sqrt(x));
}

int main() {
	prep();
	int T;
	scanf("%d", &T);
	long long le, ri;
	while (T --) {
		scanf("%I64d %I64d", &le, &ri);
		int ans = func(ri) - func(le - 1);
		printf("%d\n", ans);
	}

	return 0;
}