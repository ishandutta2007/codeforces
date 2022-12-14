#include <bits/stdc++.h>

using namespace std;



const int INF = 2e9;



typedef long long LL;



LL extended_euclid(LL a, LL b, LL &x, LL &y) {

	if (!b) {x = 1, y = 0; return a;}

	LL rlt = extended_euclid(b, a % b, y, x);

	y -= (a / b) * x;

	return rlt;

}



LL modular_linear_equation(LL a, LL b, LL m) {

	a = (a % m + m) % m, b = (b % m + m) % m;

	LL x, y, d = extended_euclid(a, m, x, y);

	if (b % d) return -1;

	return (x * (b / d) % m + m) % m;

//	all solutions are x * (b / d) + i * m / d. (0 <= i < d)

}



inline LL lcm(LL a, LL b) {return a / __gcd(a, b) * b;}



LL chinese_remainder(LL *r, LL *w, int n) {

	LL rlt = r[1], ww = w[1];

	for (int i = 2; i <= n; i ++) {

		LL x = modular_linear_equation(ww, r[i] - rlt, w[i]);

		if (x == -1) return -1;

		rlt = ww * x + rlt;

		ww = lcm(ww, w[i]);

	}

	return (rlt % ww + ww) % ww;

}



LL r[3], w[3];



int xx[4];

int yy[4];



int n, m, x, y, dx, dy;



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &dx, &dy);



	xx[2] = n, xx[3] = n;

	yy[1] = m, yy[3] = m;

	if (!dx) {

		if (x == 0 || x == n) {

			if (dy > 0) printf("%d %d\n", x, m);

			else printf("%d %d\n", x, 0);

		}

		else puts("-1");

		return 0;

	}

	if (!dy) {

		if (y == 0 || y == m) {

			if (dx > 0) printf("%d %d\n", n, y);

			else printf("%d %d\n", 0, y);

		}

		else puts("-1");

		return 0;

	}

	w[1] = 2 * n, w[2] = 2 * m;



	long long h = 1ll << 62;

	int ans = -1;



	for (int k = 0; k < 4; k ++) {

		r[1] = dx * (xx[k] - x);

		r[2] = dy * (yy[k] - y);

		long long tmp = chinese_remainder(r, w, 2);

		if (tmp == -1) continue;

		if (tmp < h) h = tmp, ans = k;

	}

	if (ans == -1) puts("-1");

	else printf("%d %d\n", xx[ans], yy[ans]);





	return 0;

}