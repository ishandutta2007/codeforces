#include <bits/stdc++.h>
using namespace std;

#define N 2020

const double ep = 1e-5;

int n;
double b, sum;

double func(double a) {
    int aa = a;
    return a - aa;
}

int main() {
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i ++) {
		scanf("%lf", &b);
		double x = func(b);
		if (x < ep) cnt ++;
		else sum += x;
	}
	double ans = 1e9 * 1.0;
    for (int k = max(0, n - cnt); k <= n; k ++) {
        ans = min(ans, fabs(sum - k));
    }
    printf("%.3lf\n", ans);
	return 0;
}