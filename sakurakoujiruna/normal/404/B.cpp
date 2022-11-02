#include <bits/stdc++.h>
using namespace std;

int main() {
	double a, d;
	scanf("%lf%lf", &a, &d);
	d = fmod(d, 4 * a);
	int n; scanf("%d", &n);
	double t = 0;
	for(int i = 1; i <= n; i ++) {
		t = fmod(t + d, 4 * a);
		if(t < a) printf("%.6f %.6f\n", t, 0.0);
		else if(t < 2 * a) printf("%.6f %.6f\n", a, t - a);
		else if(t < 3 * a) printf("%.6f %.6f\n", 3 * a - t, a);
		else printf("%.6f %.6f\n", 0.0, 4 * a - t);
	}
	return 0;
}