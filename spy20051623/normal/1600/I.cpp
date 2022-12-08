#include <bits/stdc++.h>

using namespace std;

long long c[1005][5];

int main() {
//	freopen("in.txt", "r", stdin);
	c[0][0] = 1;
	for (int i = 1; i < 1001; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= min(4, i); ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	int n;
	double p;
	scanf("%d%lf", &n, &p);
	for (int i = 0; i < n; ++i) {
		double ppp = (c[i][3] + c[i][2] * c[n - i][1] + c[i][1] * c[n - i][2] * 0.5) / c[n][3];
		if (ppp >= p) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}