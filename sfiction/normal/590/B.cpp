#include <cstdio>
#include <cmath>

double v, t;
double x00, y00;
double vx, vy, wx, wy;

double inline sqr(double x){
	return x * x;
}

double solve(double vx, double vy){
	double A = sqr(v) - sqr(vx) - sqr(vy);
	double B = 2 * (vx * x00 + vy * y00);
	double C = -sqr(x00) - sqr(y00);
	double det = B * B - 4 * A * C;

	return (-B + sqrt(det)) / 2.0 / A;
}

int main(){
	double x11, y11;
	scanf("%lf%lf%lf%lf", &x11, &y11, &x00, &y00);
	scanf("%lf%lf", &v, &t);
	x00 -= x11, y00 -= y11;
	scanf("%lf%lf", &vx, &vy);
	scanf("%lf%lf", &wx, &wy);

	double res;
	if ((res = solve(vx, vy)) < t)
		printf("%.12lf\n", res);
	else{
		x00 += (wx - vx) * t, y00 += (wy - vy) * t;
		printf("%.12lf\n", solve(wx, wy));
	}
	return 0;
}