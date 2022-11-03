#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1E5 + 10;

int n;
int xp, yp;
int x[MAXN], y[MAXN];

double sqr(double x){
	return x * x;
}

ll crossProduct(int x1, int y1, int x2, int y2){
	return x1 * (ll)y2 - x2 * (ll)y1;
}

int side(int x1, int y1, int x2, int y2){
	ll res = crossProduct(x1, y1, x2, y2);
	return res > 0 ? 1 : res == 0 ? 0 : -1;
}

int main(){
	scanf("%d%d%d", &n, &xp, &yp);
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &x[i], &y[i]);
		x[i] -= xp;
		y[i] -= yp;
	}
	x[n] = x[0], y[n] = y[0];
	double r1 = 1E8, r2 = 0.0;
	for (int i = 0; i < n; ++i){
		double d = sqrt(sqr(x[i]) + sqr(y[i]));
		r1 = min(r1, d);
		r2 = max(r2, d);
		int x1 = y[i] - y[i + 1], y1 = x[i + 1] - x[i];
		if (side(x1, y1, x[i], y[i]) * side(x1, y1, x[i + 1], y[i + 1]) <= 0)
			r1 = min(r1, fabs(crossProduct(x[i], y[i], x[i + 1], y[i + 1]) / sqrt(sqr(x1) + sqr(y1))));
	}
	double ans = M_PI * (sqr(r2) - sqr(r1));
	printf("%.12lf\n", ans);
	return 0;
}