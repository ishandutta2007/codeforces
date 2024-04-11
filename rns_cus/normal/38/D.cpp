#include <bits/stdc++.h>
using namespace std;
#define N 1010

const double ep = 1e-8, pi = acos(-1);

struct pnt {
	double x, y;
	pnt (double x = 0, double y = 0): x(x), y(y) {}
	inline pnt operator - (const pnt &a) const { return pnt(x - a.x, y - a.y); }
	inline pnt operator + (const pnt &a) const { return pnt(x + a.x, y + a.y); }
	inline pnt operator * (const double &a) const { return pnt(x * a, y * a); }
	inline pnt operator / (const double &a) const { return pnt(x / a, y / a); }
	inline double operator & (const pnt &a) const { return x * a.x + y * a.y; }
	inline double operator ^ (const pnt &a) const { return x * a.y - y * a.x; }
	inline void input() { x = y = 0, scanf("%lf %lf", &x, &y); }
} c[N];

double d[N], w[N];

bool out(int i, pnt C) {
	if (C.x < c[i].x - d[i] / 2 - ep || C.x > c[i].x + d[i] / 2 + ep) return 1;
	if (C.y < c[i].y - d[i] / 2 - ep || C.y > c[i].y + d[i] / 2 + ep) return 1;
	return 0;
}

bool ok(int m) {
	for (int i = 1; i < m; i ++) {
		pnt center = pnt(0, 0);
		double sum = 0;
		for (int j = i + 1; j <= m; j ++) center = center + c[j] * w[j], sum += w[j];
		center = center / sum;
		if (out(i, center)) return 0;
	}
	return 1;
}

int n, ans, stx, sty, enx, eny;

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d %d %d", &stx, &sty, &enx, &eny);
		c[i].x = 0.5 * (stx + enx);
		c[i].y = 0.5 * (sty + eny);
		d[i] = abs(stx - enx);
		w[i] = pow(d[i], 3);
	}
	for (int i = 1; i <= n; i ++) {
		if (ok(i)) ans = i;
		else break;
	}
	printf("%d\n", ans);
	return 0;
}