#include <stdio.h>
#include <math.h>
int main() {
	int n;
	scanf("%d", &n);
	if (n <= 4) puts("No solution");
	else {
		double alpha = 2 * acos(-1) / n, x = 0, y = 0, len = 500;
		for (int i = 1; i <= n - 2; i++) {
			printf("%.6f %.6f\n", x, y);
			len += 0.01;
			x += len * cos(alpha * i), y += len * sin(alpha * i);
		}
		printf("%.6f %.6f\n%.6f 0.000\n", x, y, x - y / tan(alpha * (n - 1)));
	}
}