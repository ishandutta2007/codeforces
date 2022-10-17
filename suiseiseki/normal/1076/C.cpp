#include <cstdio>
#include <cmath>
#define eps 1e-6
int main(){
	int t;
	scanf("%d",&t);
	int n;
	double a,b;
	while(t--){
		scanf("%d",&n);
		if(n*n-4*n<0){
			puts("N");
		}
		else{
			puts("Y");
			a=n*1.0-sqrt(n*n*1.0-4.0*n),b=n*1.0+sqrt(n*n*1.0-4.0*n);
			a/=2.0,b/=2.0;
			printf("%.9lf %.9lf\n",a,b);
		}
	}
	return 0;
}
////////////////