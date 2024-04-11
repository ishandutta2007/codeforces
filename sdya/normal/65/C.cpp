#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const double eps = 1e-9;
const int maxN = 11000;
int n;
double x[maxN], y[maxN], z[maxN];
double vp, vs;

double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	double dz = z1 - z2;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

double px, py, pz;

double calc(double s, double length, int i, double a) {
	double ta = (s + length * a) / vs;
	double pa = dist(px, py, pz, x[i] + a * (x[i + 1] - x[i]), y[i] + a * (y[i + 1] - y[i]), z[i] + a * (z[i + 1] - z[i])) / vp;
	return ta - pa;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		cin >> x[i] >> y[i] >> z[i];
	}
	cin >> vp >> vs;
	
	cin >> px >> py >> pz;

	double s = 0;
	for (int i = 0; i < n; ++i) {
		double left_bound = 0, right_bound = 1.0;
		double length = dist(x[i], y[i], z[i], x[i + 1], y[i + 1], z[i + 1]); 
		for (int j = 0; j < 60; ++j) {
			double a = (left_bound * 2.0 + right_bound) / 3.0;
			double b = (left_bound + right_bound * 2.0) / 3.0;
			if (calc(s, length, i, a) > calc(s, length, i, b)) {
				right_bound = b;
			} else {
				left_bound = a;
			}
		}
		if (calc(s, length, i, left_bound) >= -eps) {
			double lb = 0, rb = left_bound;
			for (int j = 0; j < 60; ++j) {
				double mb = (lb + rb) / 2.0;
				if (calc(s, length, i, mb) >= 0) {
					rb = mb;
				} else {
					lb = mb;
				}
			}
			printf("YES\n");
			printf("%.10lf\n", (s + length * lb) / vs);
			printf("%.10lf %.10lf %.10lf\n", x[i] + lb * (x[i + 1] - x[i]), y[i] + lb * (y[i + 1] - y[i]), z[i] + lb * (z[i + 1] - z[i]));
			return 0;
		}
		s += length;
	}
	printf("NO\n");

	return 0;
}