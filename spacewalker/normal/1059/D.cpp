#include <bits/stdc++.h>

using namespace std;

void printAns(double x) {
	if (x == -1) printf("-1\n");
	else printf("%.9lf\n", x);
	exit(0);
}

int main() {
	int n; scanf("%d", &n);
	vector<pair<int, int>> pts(n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &pts[i].first, &pts[i].second);
	if (pts[0].second < 0) {
		for (auto &x_y : pts) x_y.second *= -1;
	}
	for (auto x_y : pts) if (x_y.second < 0) printAns(-1);
	double lo = 0, hi = 6e13;
	for (auto x_y : pts) lo = max(lo, x_y.second / 2.0);
	for (int iter = 0; iter < 80; ++iter) {
		double mid = (lo + hi) / 2.0;
		double firstPoint = -INFINITY, lastPoint = INFINITY;
		for (int i = 0; i < n; ++i) {
			double cwidth = sqrt(2 * mid * pts[i].second - (double)pts[i].second * pts[i].second);
			firstPoint = max(firstPoint, pts[i].first - cwidth);
			lastPoint = min(lastPoint, pts[i].first + cwidth);
		}
		if (firstPoint <= lastPoint) hi = mid;
		else lo = mid;
	}
	printAns(lo);
	return 0;
}