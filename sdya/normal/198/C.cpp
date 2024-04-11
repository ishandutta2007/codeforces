#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct point {
	double x, y;
	point() {
	}
	point(double x, double y) : x(x), y(y) {
	}
};

double dist(const point &A, const point &B) {
	double dx = A.x - B.x;
	double dy = A.y - B.y;
	return sqrt(dx * dx + dy * dy);
}

double calculate(const point &A, const point &B, double r) {
	point C(0.0, 0.0);
	double CA = dist(C, A), CB = dist(C, B), AB = dist(A, B);
	double ang1 = acos((CB * CB + CA * CA - AB * AB) / 2.0 / CB / CA);
	if (fabs(r) < 1e-9)	{
		return AB;
	}

	double CC = CA, BB = r, AA = sqrt(CA * CA - r * r);
	double ang2 = acos((CC * CC + BB * BB - AA * AA) / 2.0 / CC / BB);
	CC = CB, BB = r, AA = sqrt(CB * CB - r * r);
	double ang3 = acos((CC * CC + BB * BB - AA * AA) / 2.0 / CC / BB);

	if (ang2 + ang3 > ang1) {
		return AB;
	} else {
		return sqrt(CA * CA - r * r) + sqrt(CB * CB - r * r) + (ang1 - ang2 - ang3) * r;
	}
}

const double pi = 2.0 * acos(0.0);

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int xp, yp, vp;
	cin >> xp >> yp >> vp;
	int x, y, v, curR;
	cin >> x >> y >> v >> curR;

	point A((double)(x), (double)(y));
	point B((double)(xp), (double)(yp));
	double R = dist(point(0.0, 0.0), B);

	double start = atan2(B.y, B.x);

	double l = 0.0, r = 1e18;
	int iterations = 0;
	bool good = false;
	while (iterations <= 200) {
		++iterations;
		double key = (l + r) / 2.0;
		double angle = (double)(vp) * (double)(key) / R;
		point bufB(cos(angle + start) * R, sin(angle + start) * R);

		double d = calculate(A, bufB, (double)(curR)) / (double)(v);
		if (d <= key) {
			good = true;
			r = key;
		} else {
			l = key;
		}
	}

	printf("%.10lf\n", (l + r) / 2.0);

	return 0;
}