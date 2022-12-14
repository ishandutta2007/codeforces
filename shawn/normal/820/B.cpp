#include <bits/stdc++.h>

using namespace std;

double n, a, b, c, d, e, t, x;
int ans;
int main() {
	scanf("%lf%lf", &n, &a);
	b = (n - 2) * 180, c = n, d = b / n, t = 1e9;
	for (int i = 3; i <= n; i ++) {
		e = b - (c - 2) * d;
		e /= 2;
		if (abs(e - a) <= t) ans = i, t = abs(e - a), x = e;
		b -= 180, c --;
	}
//	printf("%lf %lf %lf %lf %lf\n", b, c, d, e, e);
	printf("1 2 %d\n", ans);
	return 0;	
}