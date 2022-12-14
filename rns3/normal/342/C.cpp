#include <bits/stdc++.h>
using namespace std;

int h, r;

const double pi = acos(-1);

int main() {
	scanf("%d %d", &r, &h);
	int a = ((2 * h + r) / (2 * r)) * 2;
	double x = 1.0 * r * sin(pi / 3);
	double hhh = h + r - x;
	int hh = hhh;
	int b = 1 + 2 * (hh / r);
	printf("%d\n", max(a, b));
	return 0;
}