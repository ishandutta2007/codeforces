#include <cstdio>
#include <cmath>
#define sqr(x) ((x) * (x))
const int N = 5005;
double ans = 1e99;
double x[N], y[N], z[N];
int n;

double D(int i, int j)
{return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]));}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
	for (int j = 2; j <= n; ++j) for (int k = j + 1; k <= n; ++k) {
		double cur = D(1, j) + D(j, k) + D(1, k);
		if (cur < ans) ans = cur;
	}
	printf("%0.8lf\n", ans / 2);
}