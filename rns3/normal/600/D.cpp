#include <bits/stdc++.h>
using namespace std;

long double x, x2, y, y2, r, r2;

const long double pi = acos(-1);
double X1, X2, Y1, Y2, R1, R2;


int main() {
	scanf("%lf %lf %lf %lf %lf %lf", &X1, &Y1, &R1, &X2, &Y2, &R2);
	x = X1, x2 = X2, y = Y1, y2 = Y2, r = R1, r2 = R2;
    long double d, p, s, u, u2, ans;
    d = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
    if (d >= r + r2) {
		puts("0");
		return 0;
    }
    if (r < r2) swap(r, r2);
    if (r >= d + r2) {
		ans = r2 * r2 * pi;
		printf("%.12lf\n", (double)ans);
		return 0;
    }
    bool tag = 0;
    if (r2 * r2 + d * d <= r * r) tag = 1;

    p = (d + r + r2) * 0.5;
	s = 2 * sqrt(p * (p - d) * (p - r) * (p - r2));
    u = asin(s / (r * d));
    u2 = asin(s / (r2 * d));
    if (tag) u2 = pi - u2;
    ans = (u * r * r + u2 * r2 * r2) - s;
    printf("%.12lf\n", (double)ans);
	return 0;
}