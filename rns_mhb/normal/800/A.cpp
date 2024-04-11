#include<bits/stdc++.h>
using namespace std;
#define N 100010
int n, p, a[N], b[N];
long long sa, sb;

bool check(double c) {
	double sum = 0;
	for (int i = 1; i <= n; i ++) sum += max(0.0, c * a[i] - b[i]);
	return p * c >= sum;
}

int main() {
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i ++) scanf("%d%d", &a[i], &b[i]), sa += a[i], sb += b[i];
	if (p >= sa) puts("-1");
	else {
		double l = 0, r = 1.0 * sb / (sa - p) + 1e-4;
		int runs = 50;
		while (runs --) {
			double m = (l + r) / 2;
			if (check(m)) l = m;
			else r = m;
		}
		assert(abs(r - l) < 1e-4);
		printf("%.12lf", l);
	}
}