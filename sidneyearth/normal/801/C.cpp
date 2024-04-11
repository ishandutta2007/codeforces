#include <cstdio>
#include <algorithm>
using namespace std;
const double eps = 1e-9;
double a[100100], b[100100];
bool Check(double t, int n, double p){
	double s = p * t;
	for(int i = 1; i <= n; i++)
		s -= max(0.0, a[i] * t - b[i]);
	return s >= 0;
}
int main(){
	int n; scanf("%d", &n);
	double p, s = 0; 
	scanf("%lf", &p);
	for(int i = 1; i <= n; i++){
		scanf("%lf%lf", &a[i], &b[i]);
		s += a[i];
	}
	if(p >= s) printf("-1\n");
	else{
		double l = 0, r = 1e11;
		while(r - l > eps){
			double mid = (l + r) / 2;
			if(Check(mid, n, p)) l = mid;
			else r = mid;
		}
		printf("%lf\n", l);
	}
	return 0;
}