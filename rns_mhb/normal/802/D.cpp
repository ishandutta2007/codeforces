#include <bits/stdc++.h>
using namespace std;

#define N 2020

const int n = 250;

int a[N];

int main() {
	//freopen("1.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T --) {
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

		long long s = 0, t = 0;
		for (int i = 1; i <= n; i ++) s += a[i], t += a[i] * a[i];

		long double x = 1.0 * s / n;
		x *= x;
		long double y = 1.0 * t / n;
		//cerr << y / x << endl;

		bool type = 0;

		if (y / x > 7.0 / 6.0) type = 1;

		puts(type ? "uniform" : "poisson");
	}

	return 0;
}