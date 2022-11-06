#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct Point {
	int x, y;
	
	Point(int x = 0, int y = 0) : x(x), y(y) {}
};

bool operator < (const Point &a, const Point &b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

Point operator - (const Point &a, const Point &b) {
	return Point(a.x - b.x, a.y - b.y);
}

long long cross(const Point &a, const Point &b) {
	return (long long)a.x * b.y - (long long)a.y * b.x;
}

const int BAR = 100000;

int n;

double ansr;

Point ans[3];

inline double sqr(double x) {
	return x * x;
}

double ex(const Point &a, const Point &b, const Point &c) {
	double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (sqr(a1) + sqr(b1)) / 2,
		   a2 = c.x - a.x, b2 = c.y - a.y, c2 = (sqr(a2) + sqr(b2)) / 2,
		   d = a1 * b2 - a2 * b1;
	return sqrt(sqr((c1 * b2 - c2 * b1) / d) + sqr((a1 * c2 - a2 * c1) / d));
}

double cal(Point a, Point b, Point c) {
	if (cross(b - a, c - a) == 0) {
		return 0;
	}
	return ex(a, b, c);
}

void update(const Point &a, const Point &b, const Point &c) {
	double tmpr = cal(a, b, c);
	if (tmpr > ansr) {
		ansr = tmpr;
		ans[0] = a, ans[1] = b, ans[2] = c;
	}
}

int main() {
	scanf("%d", &n);
	vector<Point> p;
	for (int i = 0; i < n; ++i) {
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		if (y + v <= BAR) {
			p.push_back(Point(x, y + v));
		} else {
			int d = v - (BAR - y);
			p.push_back(Point(max(0, x - d), BAR));
			p.push_back(Point(min(BAR, x + d), BAR));
		}
		if (y - v >= 0) {
			p.push_back(Point(x, y - v));
		} else {
			int d = v - y;
			p.push_back(Point(max(0, x - d), 0));
			p.push_back(Point(min(BAR, x + d), 0));
		}
		if (x + v <= BAR) {
			p.push_back(Point(x + v, y));
		} else {
			int d = v - (BAR - x);
			p.push_back(Point(BAR, max(0, y - d)));
			p.push_back(Point(BAR, min(BAR, y + d)));
		}
		if (x - v >= 0) {
			p.push_back(Point(x - v, y));
		} else {
			int d = v - x;
			p.push_back(Point(0, max(0, y - d)));
			p.push_back(Point(0, min(BAR, y + d)));
		}
	}
	sort(p.begin(), p.end());
	vector<Point> con;
	for (int i = 0; i < (int)p.size(); ++i) {
		while (con.size() > 1 && cross(con[con.size() - 1] - con[con.size() - 2], p[i] - con[con.size() - 2]) <= 0) {
			con.pop_back();
		}
		con.push_back(p[i]);
	}
	int m = con.size();
	for (int i = (int)p.size() - 2; i >= 0; --i) {
		while (con.size() > m && cross(con[con.size() - 1] - con[con.size() - 2], p[i] - con[con.size() - 2]) <= 0) {
			con.pop_back();
		}
		con.push_back(p[i]);
	}
	/*
	for (int i = 0; i < (int)con.size(); ++i) {
		cout << con[i].x << ' ' << con[i].y << endl;
	}*/
	ansr = 0;
	for (int i = 0; i + 1 < (int)con.size(); ++i) {
				update(con[i], con[i + 1], con[(i + 2) % con.size()]);
	}
	for (int i = 0; i < 3; ++i) {
		printf("%d %d\n", ans[i].x, ans[i].y);
	}
	return 0;
}