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
double s;
double a, b, c;

double calcValue(double sum, double &y, double &z) {
	if (fabs(b + c) < eps) {
		y = sum;
		z = 0.0;
	} else {
		y = b * sum / (b + c);
		z = sum - y;
	}

	double res = 0.0;
	if (fabs(b) > eps) {
		if (y < eps) {
			res += -1e100;
		} else {
			res += b * log(y);
		}
	}
	if (fabs(c) > eps) {
		if (z < eps) {
			res += -1e100;
		} else {
			res += c * log(z);
		}
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> s >> a >> b >> c;

	double x, y, z;
	double left_bound = 0, right_bound = s;
	for (int i = 0; i < 100; ++i) {
		double u = (2.0 * left_bound + right_bound) / 3.0;
		double v = (left_bound + 2.0 * right_bound) / 3.0;
		double sA = 0., sB = 0.;
		if (fabs(a) > eps) {
			if (u < eps) {
				sA += -1e100;
			} else {
				sA += a * log(u);
			}
			if (v < eps) {
				sB += -1e100;
			} else {
				sB += a * log(v);
			}
		}
		if (calcValue(s - u, y, z) + sA > calcValue(s - v, y, z) + sB) {
			right_bound = v;
		} else {
			left_bound = u;
		}
	}

	x = left_bound;
	calcValue(s - x, y, z);
	printf("%.10lf %.10lf %.10lf\n", x, y, z);


	return 0;
}