#include <bits/stdc++.h>
using namespace std;

double n, r, a, x, pie = acos(-1);

int main() {
//	freopen("p.in", "r", stdin);
	scanf("%lf %lf", &n, &r);
	a = pie / n;
	x = r * sin(a / 2) / cos(pie / 2 - 1.5 * a);
	printf("%.12lf\n", r * x * sin(a) * n);
	return 0;
}