#include <bits/stdc++.h>
using namespace std;

double l, a, r, h, ans, pie = acos(-1);

int main() {
//	freopen("q.in", "r", stdin);
	for (int i = 3; i <= 5; i ++) {
		scanf("%lf", &l);
		a = pie / i;
		r = l / 2 / sin(a);
		h = sqrt(l * l - r * r);
		ans += l * r * cos(a) / 2 * h / 3 * i;
	}
	printf("%.12lf\n", ans);
	return 0;
}