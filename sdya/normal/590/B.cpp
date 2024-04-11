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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	double vmax, t;
	cin >> vmax >> t;

	double vx, vy, wx, wy;
	cin >> vx >> vy >> wx >> wy;

	double left_bound = 0.0, right_bound = 1e30;
	for (int i = 0; i < 200; ++i) {
		double middle = (left_bound + right_bound) / 2;

		double d1 = (middle >= t ? t : middle);
		double d2 = (middle >= t ? (middle - t) : 0);

		double x3 = x2 - d1 * vx - d2 * wx;
		double y3 = y2 - d1 * vy - d2 * wy;

		double d = dist(x1, y1, x3, y3);
		double needed = d / vmax;

		if (needed <= middle) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}
	printf("%.10lf\n", (left_bound + right_bound) / 2.0);

	return 0;
}