#include <cstdio>
#include <cmath>

int main(){
	double px, py, vx, vy, a, b, c, d;
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &px, &py, &vx, &vy, &a, &b, &c, &d);
	double l = sqrt(vx * vx + vy * vy);
	vx /= l, vy /= l;
	a /= 2, c /= 2;
	printf("%.20f %.20f\n", px + vx * b, py + vy * b);
	printf("%.20f %.20f\n", px - vy * a, py + vx * a);
	printf("%.20f %.20f\n", px - vy * c, py + vx * c);
	printf("%.20f %.20f\n", px - vy * c - vx * d, py + vx * c - vy * d);
	printf("%.20f %.20f\n", px + vy * c - vx * d, py - vx * c - vy * d);
	printf("%.20f %.20f\n", px + vy * c, py - vx * c);
	printf("%.20f %.20f\n", px + vy * a, py - vx * a);
	return 0;
}