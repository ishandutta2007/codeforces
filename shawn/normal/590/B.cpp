#include <bits/stdc++.h>

using namespace std;

int x1_1, y1_1, x2_1, y2_1, vmax, t, vx, vy, wx, wy;
double ans;

double dis(double x1_1, double y1_1, double x2_1, double y2_1) {
	return (x1_1 - x2_1) * (x1_1 - x2_1) + (y1_1 - y2_1) * (y1_1 - y2_1);
}

bool chk(double mid) {
	double X, Y;
	if (mid - t * 1.0 >= 1e-7) {
		X = x1_1 * 1.0 + vx * t * 1.0 + wx * 1.0 * (mid - 1.0 * t);
		Y = y1_1 * 1.0 + vy * t * 1.0 + wy * 1.0 * (mid - 1.0 * t);
	}
	else X = x1_1 * 1.0 + vx * 1.0 * mid, Y = y1_1 * 1.0 + vy * 1.0 * mid;
	if (dis(X, Y, x2_1 * 1.0, y2_1 * 1.0) < (vmax * 1.0 * mid) * (vmax * 1.0 * mid)) return 1;
	return 0;
}

int main() {
	scanf("%d%d%d%d%d%d", &x1_1, &y1_1, &x2_1, &y2_1, &vmax, &t);
	scanf("%d%d%d%d", &vx, &vy, &wx, &wy);
	double l = 0.0, r = 100000000.0;
	while (fabs(r - l) > 1e-7) {
		double mid = (l + r) / 2.0;
		if (chk(mid)) r = mid, ans = mid;
		else l = mid;
	}
	printf("%.18lf\n", ans);
	return 0;
}