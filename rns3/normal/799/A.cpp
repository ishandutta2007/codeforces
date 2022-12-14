#include <stdio.h>

int main() {
	char ans[2][4] = {"NO", "YES"};
	int n, t, k, d, u, v, g;
	scanf("%d %d %d %d", &n, &t, &k, &d);
	u = (n + k - 1) / k;
	v = u * t;
	g = (v - 1) / t * k;
	if (v - 1 > d) g += (v - 1 - d) / t * k;
	puts(ans[g>=n]);
	return 0;
}