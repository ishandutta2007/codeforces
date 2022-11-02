#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct pt {
	long long x, y;
	pt() : x(0), y(0) {}
	pt(long long x, long long y) : x(x), y(y) {}
};

bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

inline long long area (pt a, pt b, pt c) {
	long long res = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	return (res > 0 ? 1 : (res < 0 ? -1 : 0));
}

inline bool intersect_1 (long long a, long long b, long long c, long long d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}

bool intersect (pt a, pt b, pt c, pt d) {
	return intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y)
		&& area(a,b,c) * area(a,b,d) <= 0
		&& area(c,d,a) * area(c,d,b) <= 0;
}

const double pi = 2.0 * acos(0.0);

double getDist(pt p, pt a, pt b) {
	double A = a.y - b.y;
	double B = b.x - a.x;
	double C = a.x * b.y - a.y * b.x;

	double d = hypot((double)(A), (double)(B));
	double len = (A * p.x + B * p.y + C) / d;
	
	double dx = A / d;
	double dy = B / d;

	double x = (double)(p.x) - len * dx;
	double y = (double)(p.y) - len * dy;

	double u = hypot((double)(a.x - b.x), (double)(a.y - b.y));
	double v = hypot((double)(a.x) - x, (double)(a.y) - y);
	double w = hypot((double)(b.x) - x, (double)(b.y) - y);
	if (fabs(u - v - w) < 1e-9) {
		return fabs(len);
	}
	return hypot((double)(p.x - a.x), (double)(p.y - a.y));
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	pt p;
	scanf("%I64d%I64d", &p.x, &p.y);
	vector < pt > a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%I64d%I64d", &a[i].x, &a[i].y);
	}

	double l = 1e10, r = 0.0;
	for (int i = 0; i < a.size(); ++i) {
		double d = hypot((double)(p.x - a[i].x), (double)(p.y - a[i].y));
		l = min(l, d);
		r = max(r, d);

		d = getDist(p, a[i], a[(i + 1) % a.size()]);
		l = min(l, d);
		r = max(r, d);
	}

	int cnt = 0;

	for (int i = 0; i < a.size(); ++i) {
		if (intersect(a[i], a[(i + 1) % a.size()], p, pt(p.x + 1000000000, p.y + 1000000001))) {
			++cnt;
		}
	}

	if (cnt % 2 == 1) {
		printf("%.10lf\n", pi * r * r);
	} else {
		printf("%.10lf\n", pi * (r * r - l * l));
	}

	return 0;
}