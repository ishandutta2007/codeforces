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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

pair < double, double > inv(double r, double x, double y) {
	double d = x * x + y * y;
	return make_pair(r * r / d * x, r * r / d * y);
}

double solve(int R, int r, int k) {
	double x1 = (double)(r * r) / (double)(2 * R);
	double x2 = (double)(r) / 2.0;
	double dr = fabs(x2 - x1) / 2.0;

	double cy = 2.0 * dr * (double)(k);
	double cx = (x1 + x2) / 2.0;

	double ang = atan2(cy, cx);
	double d = sqrt(cx * cx + cy * cy);

	double u1 = (d - dr) * cos(ang);
	double v1 = (d - dr) * sin(ang);

	double u2 = (d + dr) * cos(ang);
	double v2 = (d + dr) * sin(ang);

	pair < double, double > a = inv(r, u1, v1);
	pair < double, double > b = inv(r, u2, v2);

	double dx = a.first - b.first;
	double dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy) / 2.0;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int R, r, k;
		scanf("%d%d%d", &R, &r, &k);
		printf("%.10lf\n", solve(R, r, k));
	}


	return 0;
}