#include <cstdio>

int main(){
	double l, p, q;
	scanf("%lf%lf%lf", &l, &p, &q);
	printf("%.12lf\n", l * p / (p + q));
	return 0;
}