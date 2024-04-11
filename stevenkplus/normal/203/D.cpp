#include <cstdio>

using namespace std;

double A, B, M;
double Vx, Vy, Vz;

double bounce(double a, double b, double cur) {
	while (cur > b || cur < a) {
		if (cur > b) {
			cur = 2 * b - cur;
		} else {
			cur = 2 * a - cur;
		}
	}
	return cur;
}

int main() {
	scanf("%lf %lf %lf %lf %lf %lf", &A, &B, &M, &Vx, &Vy, &Vz);
	double time = -M / Vy;
	double x = A / 2 + Vx * time;
	double z = Vz * time;
	x = bounce(0, A, x);
	z = bounce(0, B, z);
	printf("%.10lf %.10lf\n", x, z);
	return 0;
}