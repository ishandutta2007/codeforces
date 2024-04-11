#include <cstdio>

bool f(double a, double b, double c) {
	while (b < a) b += 360;
	while (c < a) c += 360;
	return b > c;
}

int main() {
	double p, q, r, s, t;
	int a, b, c, d, e;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	p = a % 12 * 30 + b * 0.5 + c * 0.5 / 60;
	q = b * 6 + c * 0.1;
	r = c * 6;
	s = d % 12 * 30;
	t = e % 12 * 30;
	printf(f(s, t, p) && f(s, t, q) && f(s, t, r) || f(t, s, p) && f(t, s, q) && f(t, s, r) ? "YES" : "NO");
	return 0;
}