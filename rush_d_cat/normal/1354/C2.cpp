#include <bits/stdc++.h>
using namespace std;
int T, n;
int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		double ang = acos(-1) * 2 / (2 * n);
		if (n % 2 == 0) ang /= 2;
		else ang /= 4;

		double R = 0.5 / sin(acos(-1) / n / 2);
		double ans = R * cos(ang) * 2;
		printf("%.9f\n", ans);
	}
}