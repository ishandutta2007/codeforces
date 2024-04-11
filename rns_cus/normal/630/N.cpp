#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;

int main() {
//	freopen("n.in", "r", stdin);
	scanf("%lf %lf %lf", &a, &b, &c);
	b /= a, c /= a, a = 1;
	d = sqrt(b * b - 4.0 * a * c);
	printf("%.12lf\n%.12lf\n", (-b + d) / (2.0 * a), (-b - d) / (2.0 * a));
	return 0;
}