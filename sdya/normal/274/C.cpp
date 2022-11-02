#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct pt {
	int x, y;
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

const int maxN = 110;
int n;
int x[maxN], y[maxN];
double d[maxN][maxN];
int dd[maxN][maxN];
int a[maxN][maxN][maxN];

double dist(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}

double res = 0.0;
const double eps = 1e-9;

int getScalar(int i, int j, int k) {
	return (x[i] - x[j]) * (x[i] - x[k]) + (y[i] - y[j]) * (y[i] - y[k]);
}

void getCenter(int i, int j, int k, double& u, double& v) {
	double a = d[j][k];
	double b = d[i][k];
	double c = d[i][j];

	double S = (double)(::a[i][j][k]) / 2.0;
	S = 8.0 * S * S;

	double A = (a * a) / S * getScalar(i, j, k);
	double B = (b * b) / S * getScalar(j, i, k);
	double C = (c * c) / S * getScalar(k, i, j);

	u = (double)(x[i]) * A + (double)(x[j]) * B + (double)(x[k]) * C;
	v = (double)(y[i]) * A + (double)(y[j]) * B + (double)(y[k]) * C;
}

vector < pt > w;
double wS;

double solve(int i, int j, int k) {
	int p = dd[i][j];
	int q = dd[i][k];
	int r = dd[j][k];
	if (p > q) {
		swap(p, q);
	}
	if (p > r) {
		swap(p, r);
	}
	if (q > r) {
		swap(q, r);
	}
	if (p + q - r < 0) {
		return 0.0;
	}

	double cx, cy;
	getCenter(i, j, k, cx, cy);

	/*double area = 0.0;
	for (int i = 0; i < w.size(); ++i) {
		int j = (i + 1) % w.size();
		double x1 = (double)(w[i].x) - cx;
		double y1 = (double)(w[i].y) - cy;
		double x2 = (double)(w[j].x) - cx;
		double y2 = (double)(w[j].y) - cy;
		area += fabs(x1 * y2 - x2 * y1);
	}

	if (fabs(area - wS) > eps) {
		return 0.0;
	}*/

	for (int i = 0; i < w.size(); ++i) {
		int j = (i + 1) % w.size();
		double d = dist(w[i].x, w[i].y, w[j].x, w[j].y);
		double a = dist(w[i].x, w[i].y, cx, cy);
		double b = dist(w[j].x, w[j].y, cx, cy);
		if (fabs(d - a - b) < eps) {
			return 0.0;
		}
	}

	double a = d[j][k];
	double b = d[i][k];
	double c = d[i][j];

	double S = (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]);
	S = fabs(S) / 2.0;

	if (fabs(S) < eps) {
		return 0.0;
	}

	double R = (a * b * c) / (4.0 * S);
	double L = max(a, max(b, c)) / 2.0;

	
	for (int t = 1; t <= n; ++t) {
		double current = dist(x[t], y[t], cx, cy);
		if (current < R - 1e-6) {
			return 0.0;
			//R = min(R, current);
		}
	}

	return R;
}

int getArea(int i, int j, int k) {
	int S = (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]);
	return (S > 0 ? S : -S);
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			d[i][j] = dist(x[i], y[i], x[j], y[j]);
			dd[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				a[i][j][k] = getArea(i, j, k);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		pt p;
		p.x = x[i];
		p.y = y[i];
		w.push_back(p);
	}
	convex_hull(w);
	wS = 0.0;
	for (int i = 0; i < w.size(); ++i) {
		int j = (i + 1) % w.size();
		wS += w[i].x * w[j].y - w[i].y * w[j].x;
	}
	wS = fabs(wS);

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			for (int k = j + 1; k <= n; ++k) {
				//res = max(res, solve(i, j, k));
				int S = a[i][j][k];
				bool nice = true;

				for (int l = 1; l <= n; ++l) {
					if (l == i || l == j || l == k) {
						continue;
					}
					if (a[i][j][l] + a[i][k][l] + a[j][k][l] == S) {
						nice = false;
						break;
					}
				}

				if (nice) {
					res = max(res, solve(i, j, k));
				}
			}
		}
	}

	if (res < eps) {
		printf("-1\n");
		return 0;
	}

	printf("%.10lf\n", res);

	return 0;
}