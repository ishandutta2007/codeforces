#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
        double eps = 1e-7 / n;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	long double x = -10000, t1, t2, t, sum1, sum2;
	for(double b = 10000; b > eps; b /= 2){
		t1 = t2 = t = sum1 = sum2 =  0;
		for(int i = 0; i < n; i++){
			sum1 = max(a[i] -x -b, sum1 +a[i] -x -b);
			t1 = max(sum1, t1);
			sum2 = min(a[i] -x -b, sum2 +a[i] -x -b);
			t2 = min(t2, sum2);
		}
		t1 = max(t1, -t2);
		t2 = t = sum1 = sum2 =  0;
		for(int i = 0; i < n; i++){
			sum1 = max(a[i] -x -b -eps, sum1 +a[i] -x -b -eps);
			t = max(sum1, t);
			sum2 = min(a[i] -x -b -eps, sum2 +a[i] -x -b -eps);
			t2 = min(t2, sum2);
		}
		t2 = max(-t2, t);
		if(t1 > t2) x += b;
	}
	printf("%.15Lf\n", t1);
	return 0;
}