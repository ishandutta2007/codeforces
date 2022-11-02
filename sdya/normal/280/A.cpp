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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const double EPS = 1E-9;
 
struct pt {
	double x, y;
 
	bool operator< (const pt & p) const {
		return x < p.x-EPS || abs(x-p.x) < EPS && y < p.y - EPS;
	}

	pt(double x, double y) : x(x), y(y) {
	}
	pt() {
	}
};
 
struct line {
	double a, b, c;
 
	line() {}
	line (pt p, pt q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = - a * p.x - b * p.y;
		norm();
	}
 
	void norm() {
		double z = sqrt (a*a + b*b);
		if (abs(z) > EPS)
			a /= z,  b /= z,  c /= z;
	}
 
	double dist (pt p) const {
		return a * p.x + b * p.y + c;
	}
};
 
#define det(a,b,c,d)  (a*d-b*c)
 
inline bool betw (double l, double r, double x) {
	return min(l,r) <= x + EPS && x <= max(l,r) + EPS;
}
 
inline bool intersect_1d (double a, double b, double c, double d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max (a, c) <= min (b, d) + EPS;
}
 
bool intersect (pt a, pt b, pt c, pt d, pt & left, pt & right) {
	if (! intersect_1d (a.x, b.x, c.x, d.x) || ! intersect_1d (a.y, b.y, c.y, d.y))
		return false;
	line m (a, b);
	line n (c, d);
	double zn = det (m.a, m.b, n.a, n.b);
	if (abs (zn) < EPS) {
		if (abs (m.dist (c)) > EPS || abs (n.dist (a)) > EPS)
			return false;
		if (b < a)  swap (a, b);
		if (d < c)  swap (c, d);
		left = max (a, c);
		right = min (b, d);
		return true;
	}
	else {
		left.x = right.x = - det (m.c, m.b, n.c, n.b) / zn;
		left.y = right.y = - det (m.a, m.c, n.a, n.c) / zn;
		return betw (a.x, b.x, left.x)
			&& betw (a.y, b.y, left.y)
			&& betw (c.x, d.x, left.x)
			&& betw (c.y, d.y, left.y);
	}
}

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

double area(pt &a, pt &b, pt &c) {
	double res = a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x;
	return fabs(res);
}

bool isIn(pt &a, vector<pt> &current) {
	double res = 0.0;
	for (int i = 0; i < current.size(); ++i) {
		res += area(a, current[i], current[(i + 1) % current.size()]);
	}

	double needed = area(current[0], current[1], current[2]) + area(current[2], current[3], current[0]);
	return fabs(res - needed) < 1e-9;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	vector<pt> a;
	double w, h, alpha;
	cin >> w >> h >> alpha;

	double coef = (w + h);
	w /= coef;
	h /= coef;

	alpha *= acos(0.0) / 90.0;

	a.push_back(pt(w / 2, h / 2));
	a.push_back(pt(-w / 2, h / 2));
	a.push_back(pt(-w / 2, -h / 2));
	a.push_back(pt(w / 2, -h / 2));

	vector<pt> b;
	for (int i = 0; i < 4; ++i) {
		double ang = atan2(a[i].y, a[i].x);
		double r = sqrt(a[i].x * a[i].x + a[i].y * a[i].y);

		b.push_back(pt(cos(ang - alpha) * r, sin(ang - alpha) * r));
	}

	vector <pt> res;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			pt left, right;
			if (intersect(a[i], a[(i + 1) % 4], b[j], b[(j + 1) % 4], left, right)) {
				if (isIn(left, a) && isIn(left, b)) {
					res.push_back(left);
				}
				if (isIn(right, a) && isIn(right, b)) {
					res.push_back(right);
				}
			}
		}
	}

	convex_hull(res);

	double ans = 0.0;
	for (int i = 0; i < res.size(); ++i) {
		ans += res[i].x * res[(i + 1) % res.size()].y - res[i].y * res[(i + 1) % res.size()].x;
	}
	printf("%.10lf\n", coef * coef * fabs(ans) / 2.0);

	return 0;
}