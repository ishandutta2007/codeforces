#include <bits/stdc++.h>
using namespace std;

long long a, b, c, d;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%I64d %I64d %I64d", &a, &b, &c);
if (a < 0) a = -a, b = -b, c = -c;
	if (!a && !b) {
		printf("%d\n", c ? 0 : -1); return 0;
	}
	if (!a) {
		printf("1\n%.12lf\n", -1.0 * c / b); return 0;
	}
	d = b * b - 4 * a * c;
	if (d < 0) puts("0");
	else if (!d) printf("1\n%.12lf\n", -0.5 * b / a);
	else printf("2\n%.12lf %.12lf\n", (-1.0 * b - sqrt(d)) / a / 2, (-1.0 * b + sqrt(d)) / a / 2);
	return 0;
}