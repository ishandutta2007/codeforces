#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n;
int p, q;
int x[maxN], y[maxN];

struct pt {
	double x, y;
	pt() : x(0), y(0) {}
	pt(double x, double y) : x(x), y(y) {}
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

void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}

inline double area (pt a, pt b, pt c) {
	double res = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (res < 0) {
		res = -1.0;
	}
	if (res > 0) {
		res = 1.0;
	}
	return res;
}

inline bool intersect_1 (double a, double b, double c, double d) {
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

bool check(const vector < pt > &a, double t) {
	vector < pt > b = a;
	for (int i = 0; i < b.size(); ++i) {
		b[i].x *= t;
		b[i].y *= t;
	}

	int cnt = 0;
	double x1 = (double)(1e13);
	double y1 = (double)(1e13 + 1);
	int m = b.size();
	for (int i = 0; i < m; ++i) {
		double a1 = b[i].x - b[(i + 1) % m].x;
		double b1 = (double)(p) - b[(i + 1) % m].x;

		double a2 = b[i].y - b[(i + 1) % m].y;
		double b2 = (double)(q) - b[(i + 1) % m].y;

		double l = 0, r = 1;
		if (a1 > 0) {
			l = max(l, b1 / a1);
		} else if (a1 < 0) {
			r = min(r, b1 / a1);
		} else {
			if (b1 > 0) {
				continue;
			}
		}

		if (a2 > 0) {
			l = max(l, b2 / a2);
		} else if (a2 < 0) {
			r = min(r, b2 / a2);
		} else {
			if (b2 > 0) {
				continue;
			}
		}

		if (l <= r) {
			return true;
		}
	}
	return cnt % 2 == 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &p, &q);
	vector < pt > a;
	a.push_back(pt(0.0, 0.0));
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		a.push_back(pt(x[i], y[i]));
	}
	convex_hull(a);

	double l = 0.0, r = 1e7;
	for (int i = 0; i < 50; ++i) {
		double m = (l + r) / 2.0;
		if (check(a, m)) {
			r = m;
		} else {
			l = m;
		}
	}
	printf("%.10lf\n", (l + r) / 2.0);


	return 0;
}