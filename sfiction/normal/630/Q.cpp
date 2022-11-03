#include <cmath>
#include <cstdio>

double calc(double l, double n){
	double r1 = l / 2 / sin(M_PI / n), r2 = r1 * cos(M_PI / n);
	double h = sqrt(l * l - r1 * r1);
	return n * l * r2 / 2 * h / 3;
}

int main(){
	double l1, l2, l3;
	scanf("%lf%lf%lf", &l1, &l2, &l3);
	printf("%.20f\n", calc(l1, 3) + calc(l2, 4) + calc(l3, 5));
	return 0;
}