#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d, e, f, ans;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	if (a >= d) {
		ans = 2 * (a * b + c * d + e * f) + (a - d) * (a - d);
	}
	else {
		ans = 2 * (f * a + b * c + d * e) + (a - d) * (a - d);
	}
	printf("%d\n", ans);
	return 0;
}