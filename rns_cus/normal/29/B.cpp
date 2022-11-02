#include <bits/stdc++.h>
using namespace std;

#define ep 1e-10

double l, d, v, g, r, t, x;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%lf %lf %lf %lf %lf", &l, &d, &v, &g, &r);
	t += d / v;
	if(t >= g + floor(t / (g + r)) * (g + r) - ep) t = (1.0 + floor(t / (g + r))) * (g + r);
	x += d;
	t += (l - x) / v;
	printf("%.12lf\n", t);
	return 0;
}