#include <cstdio>
#include <cmath>

int main(){
	double n, r;
	scanf("%lf%lf", &n, &r);
	double A = M_PI / n, B = A / 2;
	printf("%.20f\n", r * sin(B) / sin(M_PI - A - B) * sin(A) * r * n);
	return 0;
}