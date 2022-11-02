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

const int maxN = 2100;
int n;
int a[maxN], b[maxN], c[maxN];

struct Point {
	double x, y;
};

Point p[maxN][maxN];

void intersect(int i, int j, Point &p) {
	long long D = a[i] * b[j] - b[i] * a[j];

	long long u = c[i] * b[j] - b[i] * c[j];
	long long v = a[i] * c[j] - c[i] * a[j];

	p.x = (double)(u) / (double)(D);
	p.y = (double)(v) / (double)(D);
}

const double pi = 2.0 * acos(0.0);
const double eps = 1e-12;

pair < double, int > d[maxN];
int m;

bool differentSides(int i, double x, double y) {
	double v = (double)(a[i]) * x + (double)(b[i]) * y - (double)(c[i]);
	double u = (double)(-c[i]);

	return ((u > 0 && v < 0) || (u < 0 && v > 0));
}

bool getAngle(int i, int j, double &res) {
	if (c[j] == 0 || c[i] == 0) {
		return false;
	}

	double dx = -b[j];
	double dy = a[j];

	double x = p[i][j].x + dx;
	double y = p[i][j].y + dy;

	double xb = p[i][j].x - dx;
	double yb = p[i][j].y - dy;
	
	if (differentSides(i, xb, yb)) {
		x = xb;
		y = yb;
	}

	double l1 = hypot(p[i][j].x, p[i][j].y);
	double l2 = hypot(x - p[i][j].x, y - p[i][j].y);

	double prod = -p[i][j].x * (x - p[i][j].x) - p[i][j].y * (y - p[i][j].y);

	double cosvalue = prod / (l1 * l2);

	res = acos(cosvalue);
	return true;
}

bool isok(double x, double y, int i, int j, int k) {
	Point u = p[i][j], v = p[i][k];
	double p = u.x * (-y) + u.y * x;
	double q = v.x * (-y) + v.y * x;
	return (p < 0 && q > 0) || (p > 0 && q < 0);
}

long long solve(int index) {
	m = 0;
	for (int i = 0; i < n; ++i) {
		if (i == index) {
			continue;
		}
		double value;
		if (getAngle(index, i, value)) {
			d[m++] = make_pair(value, i);
		}
	}
	sort(d, d + m);

	long long res = 0;
	for (int i = 0; i < m; ++i) {
		double needed = pi - d[i].first;

		int l = lower_bound(d + i + 1, d + m, make_pair(needed - eps, -1)) - d;
		int r = upper_bound(d + i + 1, d + m, make_pair(needed + eps, -1)) - d;
		for (int j = l; j < r; ++j) {
			Point p = ::p[d[i].second][d[j].second];
			if (differentSides(index, p.x, p.y) && isok(p.x, p.y, index, d[i].second, d[j].second)) {
				++res;
			}
		}
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			intersect(i, j, p[i][j]);
			p[j][i] = p[i][j];
		}
	}

	long long res = 0;
	for (int i = 0; i < n; ++i) {
		res += solve(i);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (c[i] == 0 && c[j] == 0) {
				res += n - 2;
			}
		}
	}

	cout << res << endl;


	return 0;
}