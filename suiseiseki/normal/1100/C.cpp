#include <cstdio>
#include <cmath>
#define M_PI 3.14159265358979323846
int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	double x=sin(2*M_PI/(2.0*n));
	printf("%.7lf\n",(r*x)/(1-x));
	return 0;
}