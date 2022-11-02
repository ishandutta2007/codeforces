#include <bits/stdc++.h>
using namespace std;
int n, p, a[100009], b[100009];
double solve(double x) {
	double ret = 0.0;
	for(int i = 0; i < n; i++) {
		if(a[i] * x > b[i]) ret += a[i] * x - b[i];
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &p);
	for(int i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
	double l = 0.0, r = 1.0e+14;
	for(int i = 0; i < 150; i++) {
		double m = (l + r) * 0.5;
		if(solve(m) < p * m) l = m;
		else r = m;
	}
	if(l >= 1.0e+13) puts("-1");
	else printf("%.12lf\n", l);
	return 0;
}