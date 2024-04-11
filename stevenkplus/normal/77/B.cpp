#include <cstdio>

using namespace std;

int T;

int main() {
	scanf("%d", &T);
	for(int i = 0; i < T; ++i) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		if (b == 0) {
			printf("1\n");
		} else if (a == 0) {
			printf("0.5\n");
		} else {
			double tot = a * (2 * b);
			double good = a * b;

			double bmax = a / 4.;
			if (bmax <= b) {
				good += a * bmax / 2;
			} else {
				double alim = b * 4;
				good += alim * b / 2;
				good += (a - alim) * b;
			}
			double prob = good / tot;
			printf("%.10lf\n", prob);
		}
	}

	return 0;
}