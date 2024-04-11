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

double getValue(double p, double b) {
	return p * p / 8.0 + p * b;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		double a, b;
		scanf("%lf%lf", &a, &b);
		if (fabs(b) < 1e-9) {
			printf("%.10lf\n", 1.0);
			continue;
		}
		if (fabs(a) < 1e-9) {
			printf("%.10lf\n", 0.5);
			continue;
		}
		double res = 0.0;
		if (a <= 4.0 * b) {
			res = getValue(a, b);
		} else {
			res = getValue(4.0 * b, b) + (a - 4.0 * b) * 2.0 * b;
		}
		res /= 2.0 * a * b;
		printf("%.10lf\n", res);
	}

	return 0;
}