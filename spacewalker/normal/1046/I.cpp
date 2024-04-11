#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using point = pair<double, double>;

point perpFromOrigin(double x1, double y1, double x2, double y2) {
	if (x1 == x2) {
		return make_pair(x1, 0);
	} else if (y1 == y2) {
		return make_pair(0, y1);
	} else {
		double m = (y2 - y1) / (x2 - x1);
		double b = y1 - m * x1;
		// -x/m = mx + b
		// (-m - 1/m)x = b
		// x = -b/(m + 1/m)
		double ptx = - b / (m + 1/m);
		double pty = m * ptx + b;
		return make_pair(ptx, pty);
	}
}

double sqDistFromOrigin(point x) {
	return x.first * x.first + x.second * x.second;
}

double minSqDist(point a, point b, point c, point d) {
	point rela(c.first - a.first, c.second - a.second);
	point relb(d.first - b.first, d.second - b.second);
//	printf("relpt %.2lf %.2lf %.2lf %2lf\n", rela.first, relb.first, rela.second, relb.second);
	if (rela == relb) return sqDistFromOrigin(rela);
	point lineProj = perpFromOrigin(rela.first, rela.second, relb.first, relb.second);
//	printf("lproj %.2lf %.2lf\n", lineProj.first, lineProj.second);
	if ((lineProj.first - rela.first) * (lineProj.first - relb.first) <= 0
		&& (lineProj.second - rela.second) * (lineProj.second - relb.second) <= 0) {
		return sqDistFromOrigin(lineProj);
	} else {
		return min(sqDistFromOrigin(rela), sqDistFromOrigin(relb));
	}
}

int main() {
//	int a, b, c, d, e, f, g, h; scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);
//	printf("%.3lf\n", minSqDist(make_pair(a, b), make_pair(c, d), make_pair(e, f), make_pair(g, h)));
//	return 0;
	int n; scanf("%d", &n);
	int d1, d2; scanf("%d %d", &d1, &d2);
	vector<point> aline, bline;
	for (int i = 0; i < n; ++i) {
		int ax, ay, bx, by; scanf("%d %d %d %d", &ax, &ay, &bx, &by);
		aline.emplace_back(ax, ay);
		bline.emplace_back(bx, by);
	}
	vector<double> distMarker;
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			distMarker.push_back(minSqDist(aline[i-1], aline[i], bline[i-1], bline[i]));
		}
		distMarker.push_back(minSqDist(aline[i], aline[i], bline[i], bline[i]));
	}
	bool haveTalked = false, d2Reach = false;
	int ans = 0;
	for (int i = 0; i < distMarker.size(); ++i) {
//		printf("dist pt %d %.4lf\n", i, sqrt(distMarker[i]));
		if (distMarker[i] <= d1 * d1 && (!haveTalked || d2Reach)) {
			++ans;
			haveTalked = true;
			d2Reach = false;
		} else if (distMarker[i] > d2 * d2) d2Reach = true;
	}
	printf("%d\n", ans);
	return 0;
}