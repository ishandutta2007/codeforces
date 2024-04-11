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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const double eps = 1e-9;
const double pi = 2.0 * acos(0.0);
double r, h;

double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	double dz = z1 - z2;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

double dist(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}

double solve(double x1, double y1, double z1, double x2, double y2, double z2) {
	if (fabs(z1) < eps && fabs(z2) < eps) {
		return dist(x1, y1, z1, x2, y2, z2);
	}

	double l1 = dist(x1, y1, z1, 0, 0, h);
	double l2 = dist(x2, y2, z2, 0, 0, h);

	if (fabs(l1) < eps || fabs(l2) < eps) {
		return l1 + l2;
	}

	double coef = l2 / l1;
	double xn = x1 * coef;
	double yn = y1 * coef;
	double zn = h + (z1 - h) * coef;
	double cr = sqrt(l2 * l2 - (h - z2) * (h - z2));
	double ang = acos((xn * x2 + yn * y2) / (cr * cr));

	double length = ang * r;
	double alpha = length / sqrt(r * r + h * h);

	double u1 = l1, v1 = 0.0;
	double u2 = l2 * cos(alpha), v2 = l2 * sin(alpha);

	return dist(u1, v1, u2, v2);
}

double calc(double xa, double ya, double za, double xb, double yb, double zb, double x0, double y0, double z0, double L, double R) {
	double res = 1e20;
	double d = solve(xa, ya, za, x0, y0, z0);
	for (int i = 0; i < 30; ++i) {
		double x = (2.0 * L + R) / 3.0;
		double y = (L + 2.0 * R) / 3.0;

		double x1 = r * cos(x), y1 = r * sin(x);
		double x2 = r * cos(y), y2 = r * sin(y);

		double A = solve(x0, y0, z0, x1, y1, 0.0) + solve(x1, y1, 0.0, xb, yb, zb);
		double B = solve(x0, y0, z0, x2, y2, 0.0) + solve(x2, y2, 0.0, xb, yb, zb);
		res = min(res, d + A);
		res = min(res, d + B);
		if (A < B) {
			R = y;
		} else {
			L = x;
		}
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> r >> h;
	double xa, ya, za;
	double xb, yb, zb;
	cin >> xa >> ya >> za;
	cin >> xb >> yb >> zb;

	double res = 1e20;
	if (fabs(za) > eps && fabs(zb) > eps) {
		res = min(res, solve(xa, ya, za, xb, yb, zb));
	}
	if (fabs(za) < eps && fabs(zb) < eps) {
		res = min(res, dist(xa, ya, za, xb, yb, zb));
	}

	double angle = 2.0 * pi / 100;
	for (int step = 0; step < 100; ++step) {
		double left_bound = (double)(step) * angle;
		double right_bound = (double)(step + 1) * angle;

		for (int i = 0; i < 60; ++i) {
			double L = (2.0 * left_bound + right_bound) / 3.0;
			double R = (left_bound + 2.0 * right_bound) / 3.0;

			double valueL = solve(xa, ya, za, r * cos(L), r * sin(L), 0) + solve(r * cos(L), r * sin(L), 0, xb, yb, zb);
			double valueR = solve(xa, ya, za, r * cos(R), r * sin(R), 0) + solve(r * cos(R), r * sin(R), 0, xb, yb, zb);
			res = min(res, valueL);
			res = min(res, valueR);
			if (valueL < valueR) {
				right_bound = R;
			} else {
				left_bound = L;
			}
		}
	}
	//printf("%.12lf\n", res);
	int cnt = 8;
	angle = 2.0 * pi / (double)(cnt);
	for (int stepA = 0; stepA < cnt; ++stepA) {
		for (int stepB = 0; stepB < cnt; ++stepB) {
			double left_bound = (double)(stepA) * angle;
			double right_bound = (double)(stepA + 1) * angle;

			double lB = (double)(stepB) * angle;
			double rB = (double)(stepB + 1) * angle;
			for (int i = 0; i < 30; ++i) {
				double L = (2.0 * left_bound + right_bound) / 3.0;
				double R = (left_bound + 2.0 * right_bound) / 3.0;

				double valueL = calc(xa, ya, za, xb, yb, zb, r * cos(L), r * sin(L), 0.0, lB, rB);
				double valueR = calc(xa, ya, za, xb, yb, zb, r * cos(R), r * sin(R), 0.0, lB, rB);
				res = min(res, valueL);
				res = min(res, valueR);
				if (valueL < valueR) {
					right_bound = R;
				} else {
					left_bound = L;
				}
			}
		}
	}

	printf("%.12lf\n", res);

	return 0;
}