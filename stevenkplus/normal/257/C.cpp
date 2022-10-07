#include <cstdio>
#include <algorithm>
#include <complex>

using namespace std;

typedef complex<double> point;

const double PI = acos(-1.0);
const int MAXN = 100100;
double args[MAXN];

int N;

double getArg(double a, double b) {
	point p(a, b);
	double rads = arg(p);
	double degs = rads * 180 / PI;
	return degs;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		double arg = getArg(a, b);
		args[i] = arg;
	}

	sort(args, args + N);
	args[N] = args[0] + 360;

	double ans = 360;
	for(int i = 0; i < N; ++i) {
		double cur = args[i + 1];
		double prv = args[i];
		double diff = cur - prv;
		double need = 360 - diff;
		ans = min(ans, need);
	}

	printf("%.20f\n", ans);
	return 0;
}