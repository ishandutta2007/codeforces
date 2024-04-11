#include <bits/stdc++.h>
using namespace std;

double last = 0;
double a, d;

double sqr(double q) {
	return q * q;
}

int main (int argc, char *argv[])
{
	int n;
	scanf("%d%lf%lf", &n, &a, &d);
	while(n--) {
		double t, v;
		double dd = d;
		scanf("%lf%lf", &t, &v);
		double new_t = v / a,
			new_d = sqr(new_t) * a / 2;
		if(new_d >= dd) {
			new_t = sqrt(2 * dd / a);
			t += new_t;
			t = max(t, last);
			last = t;
			printf("%.8lf\n", last);
		} else {
			dd -= new_d;
			t += new_t;
			t += dd / v;
			t = max(t, last);
			last = t;
			printf("%.8lf\n", last);
		}
	}
	
	return 0;
}