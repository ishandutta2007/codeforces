#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double pi = 2.0 * acos(0.0);

int main() {
	double x1, y1;
	double x2, y2;
	double x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	double a = atan2(y2 - y1, x2 - x1);
	double b = atan2(y3 - y2, x3 - x2);
	double r = b - a;
	while (r < 0.0) {
		r += 2.0 * pi;
	}
	while (r >= 2.0 * pi) {
		r -= 2.0 * pi;
	}

	
	const double eps = 1e-9;
	if (fabs(r) < eps) {
		printf("TOWARDS");
	} else if (fabs(r - pi / 2.0) < eps) {
		printf("LEFT");
	} else {
		printf("RIGHT");
	}
	return 0;
}