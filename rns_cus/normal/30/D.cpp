///	D : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, k;
double x[N], y[N], sum, ans, ans0, ans1, ans2, d[N];

inline double dist(double x, double y) {return sqrt(x * x + y * y);}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d", &n, &k);
	k --;
	for (int i = 0; i < n; i ++) scanf("%lf", &x[i]);
	scanf("%lf %lf", &x[n], &y[n]);
	int xx = x[k];
	sort(x, x + n);
	sum = x[n-1] - x[0];
	for (int i = 0; i < n; i ++) d[i] = dist(x[n] - x[i], y[n] - y[i]);

	ans0 = sum + min(d[0], d[n-1]);
	ans1 = sum + d[n-1];
	for (int i = 0; i < n - 1; i ++) {
		ans1 = min(ans1, sum - (x[i+1] - x[i]) + d[i] + min(d[i+1], d[n-1]));
	}
	ans2 = sum + d[0];
	for (int i = n - 1; i >= 1; i --) {
		ans2 = min(ans2, sum - (x[i] - x[i-1]) + d[i] + min(d[i-1], d[0]));
	}
	if (k == n) {
		printf("%.8lf\n", ans0); return 0;
	}
	for (int i = 0; i < n; i ++) if (x[i] == xx) k = i;
	if (!k) {
		printf("%.8lf\n", ans1); return 0;
	}
	if (k == n - 1) {
		printf("%.8lf\n", ans2); return 0;
	}
	ans = min(x[k] - x[0] + ans1, x[n-1] - x[k] + ans2);
	ans = min(ans, d[k] + ans0);
	ans = min(ans, sum - (x[k+1] - x[k]) + d[0] + min(d[k+1], d[n-1]));
	ans = min(ans, sum - (x[k] - x[k-1]) + d[n-1] + min(d[k-1], d[0]));
	for (int i = k; i < n - 1; i ++) {
		ans = min(ans, sum - (x[i+1] - x[i]) + (x[i] - x[k]) + d[0] + min(d[i+1], d[n-1]));
	}
	for (int i = k; i > 0; i --) {
		ans = min(ans, sum - (x[i] - x[i-1]) + (x[k] - x[i]) + d[n-1] + min(d[0], d[i-1]));
	}
	printf("%.8lf\n", ans);
	return 0;
}