#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define maxn 100500

struct Point {
	int x, y;
	Point() : x(0), y(0) {}
	Point(const int &xp, const int &yp) : x(xp - yp), y(xp + yp) {}
	bool operator<(const Point &p) const {
		return (x < p.x || x == p.x && y < p.y);
	}
};

const int INF = 2000000001;
//const int INF = 0x3f3f3f3f;

int min_l[maxn], min_r[maxn], max_l[maxn], max_r[maxn];
int n;
vector < Point > pnt;

bool ok(const double &sm) {
	int ptr = 0;
	for (int i = 0; i < n; ++i) {
		while (ptr != n && (double)pnt[ptr].x - (double)pnt[i].x <= 2. * sm) ++ptr;
		if (i == 0) {
			if (ptr == n || double(max_r[ptr]) - double(min_r[ptr]) <= 2. * sm)
				return true;
		} else if (ptr == n) {
			if (double(max_l[i - 1]) - double(min_l[i - 1]) <= 2. * sm)
				return true;
		} else {
			double mind = min(double(min_l[i - 1]), double(min_r[ptr])),
				   maxd = max(double(max_l[i - 1]), double(max_r[ptr]));
			if (maxd - mind <= 2. * sm)
				return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		pnt.push_back(Point(x, y));
	}
	sort(pnt.begin(), pnt.end());
	int cmin = INF, cmax = -INF;
	for (int i = 0; i < n; ++i) {
		min_l[i] = cmin = min(cmin, pnt[i].y);
		max_l[i] = cmax = max(cmax, pnt[i].y);
	}
	cmin = INF, cmax = -INF;
	for (int i = n - 1; i >= 0; --i) {
		min_r[i] = cmin = min(cmin, pnt[i].y);
		max_r[i] = cmax = max(cmax, pnt[i].y);
	}
	double l = 0.0, r = 2e10;
	for (int i = 0; i < 90; ++i) {
		double m = (l + r) / 2;
		if (ok(m))
			r = m;
		else
			l = m;
	}
	printf("%.16lf\n", (l + r) / 2.);
	return 0;
}