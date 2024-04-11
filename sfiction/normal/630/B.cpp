#include <cstdio>
#include <cmath>

int main(){
	double n, t;
	scanf("%lf%lf", &n, &t);
	printf("%.20f\n", n * pow(1.000000011, t));
	return 0;
}