#include <stdio.h>
#include <math.h>

double a, v, L, d, w, ans;

double calc(double a, double v, double L) {
	double t = v / a;
	double s = 0.5 * v * t;
	if (s >= L) return sqrt(2.0 * L / a);
	else return t + (L - s) / v;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%lf %lf %lf %lf %lf", &a, &v, &L, &d, &w);

	if (w >= v || w * w / (2 * a) >= d) ans = calc(a, v, L);
	else {
		double t = w / a;
		double s = 0.5 * w * t;
		double R = d - s;
		t = (v - w) / a;
		if ((v + w) * t >= R) ans = (-2.0 * w + 2.0 * sqrt(w * w + a * R)) / a;
		else ans = (R - (w + v) * t) / v + 2.0 * t;
		ans += calc(a, v, L - (d - s));
	}
	printf("%lf\n", ans);
	return 0;
}