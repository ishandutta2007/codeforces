#include <cstdio>
#include <cmath>

int main(){
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	if (a < 0)
		a *= -1, b *= -1, c *= -1;
	double det = sqrt(b * b - 4 * a * c);
	printf("%.20f\n%.20f\n", (-b + det) / a / 2.0, (-b - det) / a / 2.0);
	return 0;
}