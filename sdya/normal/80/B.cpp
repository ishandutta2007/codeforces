#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double a = acos(0.0) / 3.0;
const double pi = 2.0 * acos(0.0);

int main() {
	int x, y;
	scanf("%d:%d", &x, &y);
	x %= 12;
	int p = x % 12;
	int q = y % 60;
	
	double ra = a * (p + (double)(y) / 60.0);
	double rb = a / 5.0 * q;
	ra *= 180 / pi;
	rb *= 180 / pi;
	printf("%.10lf %.10lf\n", ra, rb);
	return 0;
}