#include <cmath>
#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, x[1009], y[1009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
	double ret = 1.0e+60;
	for (int i = 0; i < n; i++) {
		int ax = x[i] - x[(i + 1) % n];
		int ay = y[i] - y[(i + 1) % n];
		int bx = x[(i + 2) % n] - x[(i + 1) % n];
		int by = y[(i + 2) % n] - y[(i + 1) % n];
		ret = min(ret, abs(1.0 * ax * by - 1.0 * ay * bx) / sqrt(1.0 * (bx - ax) * (bx - ax) + 1.0 * (by - ay) * (by - ay)));
	}
	printf("%.12lf\n", ret * 0.5);
	return 0;
}