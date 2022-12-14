#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
double temp(double h, double c, double t, double x) {
	return abs((x * (h + c) + h) / (2 * x + 1) - t);
}
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int h, c, t;
		scanf("%d %d %d", &h, &c, &t);
		if (t <= (h + c) / 2) printf("2\n");
		else {
			int x1 = (h - t) / (2 * t - h - c), x2 = (h - t) / (2 * t - h - c) + 1;
			if (temp(h, c, t, x1) > temp(h, c, t, x2)) printf("%d\n", 2 * x2 + 1);
			else printf("%d\n", 2 * x1 + 1);
		}
	}
	return 0;
}