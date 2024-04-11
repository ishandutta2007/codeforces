#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double dist(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}

struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
};

double dist(const Point &a, const Point &b) {
	return dist(a.x, a.y, b.x, b.y);
}

struct Circle {
	Point p;
	double r;
	Circle() {}
	Circle(Point p, double r) : p(p), r(r) {}
	
	bool contains(Point q) {
		return r + 1e-10 >= dist(p, q);
	}
};

vector < Point > intersect(Circle A, Circle B) {
	double d = dist(A.p, B.p);
	double alpha = atan2(B.p.y - A.p.y, B.p.x - A.p.x);
	if (fabs(d - A.r - B.r) < 1e-12 || fabs(d - fabs(A.r - B.r)) < 1e-12) {
		vector < Point > res;
		res.push_back(Point(A.p.x + A.r * cos(alpha), A.p.y + A.r * sin(alpha)));
		return res;
	}
	if (d > A.r + B.r) {
		return vector < Point > ();
	}
	if (d < fabs(A.r - B.r)) {
		return vector < Point > ();
	}
	
	
	double shift = acos((A.r * A.r + d * d - B.r * B.r) / (2.0 * A.r * d));
	
	vector < Point > res;
	res.push_back(Point(A.p.x + A.r * cos(alpha + shift), A.p.y + A.r * sin(alpha + shift)));
	res.push_back(Point(A.p.x + A.r * cos(alpha - shift), A.p.y + A.r * sin(alpha - shift)));
	return res;
}

void add(vector < Point > &x, vector < Point > y) {
	for (int i = 0; i < y.size(); ++i) {
		x.push_back(y[i]);
	}
}

int main() {
	double t1, t2;
	cin >> t1 >> t2;
	Point a, b, c;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	
	//t1 += 1e-6;
	//t2 += 1e-6;
	
	double u = dist(a, c) + dist(c, b);
	double v = dist(a, b);
	
	if (u <= v + t2 + 1e-8) {
		printf("%.10lf\n", min(u + t1, v + t2));
		return 0;
	}
	if (t1 >= v + t2) {
		printf("%.10lf\n", v + t2);
		return 0;
	}
	
	double left_bound = 0.0, right_bound = min(u + t1 - dist(b, c), v + t2);
	for (int steps = 0; steps < 200; ++steps) {
		double middle = (left_bound + right_bound) / 2.0;
		Circle A(a, middle);
		Circle C(c, u + t1 - middle - dist(b, c));
		Circle B(b, v + t2 - middle);
		
		vector < Point > candidates;
		candidates.push_back(A.p);
		candidates.push_back(B.p);
		candidates.push_back(C.p);
		add(candidates, intersect(A, B));
		add(candidates, intersect(A, C));
		add(candidates, intersect(B, C));
		/*const int maxD = 50000;
		double shift = 4.0 * acos(0.0) / (double)(maxD);
		double ang = 0.0;
		for (int i = 0; i < maxD; ++i) {
			candidates.push_back(Point(A.p.x + A.r * cos(ang), A.p.y + A.r * sin(ang)));
			ang += shift;
		}*/
		bool success = false;
		for (int i = 0; i < candidates.size(); ++i) {
			if (A.contains(candidates[i]) && B.contains(candidates[i]) && C.contains(candidates[i])) {
				success = true;
			}
		}
		if (success) {
			left_bound = middle;
		} else {
			right_bound = middle;
		}
	}
	printf("%.10lf\n", (left_bound + right_bound) / 2.0);
	return 0;
}