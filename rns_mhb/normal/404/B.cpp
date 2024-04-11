#include<stdio.h>
#include<math.h>

int main(){
	//freopen("in.txt", "r", stdin);
	int i, j, n;
	double a, d, td, curd;
	while (~scanf("%lf %lf", &a, &d)){
		scanf("%d", &n);
		td=a*4;
		for (i=1; i<=n; i++) {
			curd=d*i;
			 curd=fmod(curd, td);
			if (curd<=a) printf("%lf %lf\n", curd, 0.);
			else if (curd>a && curd<=2*a) printf("%lf %lf\n", a, curd-a);
			else if (curd>3*a && curd<=td){
				curd=td-curd;
				printf("%lf %lf\n", 0., curd);
			}
			else if (curd>2*a && curd<=3*a){
				curd=td-curd;
				printf("%lf %lf\n", curd-a, a);
			}
		}
	}
	return 0;
}