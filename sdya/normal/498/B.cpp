#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 5100;
const double eps = 1e-12;

int n, m;
int b[maxN], a[maxN];
double p[maxN];
double d[2][maxN];

double dp[110][maxN];

inline double getValue(int u, int n) {
	if (n < 0) {
		return 0.0;
	}
	return d[u][n];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &b[i], &a[i]);
		p[i] = (double)(b[i]) / 100.0;
	}

	for (int i = 0; i <= 100; ++i) {
		double value = 1.0;
		dp[i][0] = value;
		double q = (double)(i) / 100.0;
		for (int j = 1; j < maxN; ++j) {
			dp[i][j] = dp[i][j - 1] * (1.0 - q);
			if (dp[i][j] < eps) {
				dp[i][j] = 0.0;
				break;
			}
		}
	}

	int u, v;
	u = 0, v = 1;
	for (int i = 0; i <= m; ++i) {
		d[u][i] = 0.0;
	}
	d[u][0] = 1.0;

	double res = 0.0;
	for (int i = 0; i <= n; ++i, swap(u, v)) {
		if (i == n) {
			for (int j = 0; j <= m; ++j) {
				if (d[u][j] < eps) {
					continue;
				}
				res += (double)(n) * d[u][j];
			}
			break;
		}

		for (int j = 0; j <= m; ++j) {
			if (d[u][j] < eps || a[i] <= m - j) {
				continue;
			}
			res += (double)(i) * d[u][j] * dp[b[i]][m - j];
		}

		for (int j = 0; j <= m; ++j) {
			d[v][j] = 0.0;
		}

		if (a[i] == 1) {
			for (int j = 1; j <= m; ++j) {
				d[v][j] = d[u][j - 1];
			}
			continue;
		}

		d[v][1] = d[u][0] * p[i];
		if (d[v][1] < eps) {
			d[v][1] = 0.0;
		}
		double q = dp[b[i]][a[i] - 2];
		double x = p[i] * q;
		double y = q * (1.0 - p[i]);
		for (int j = 2; j <= m; ++j) {
			d[v][j] = d[v][j - 1] - getValue(u, j - a[i] - 1) * y - getValue(u, j - a[i]) * x;
			d[v][j] *= (1.0 - p[i]);
			d[v][j] += getValue(u, j - a[i]) * y;
			d[v][j] += d[u][j - 1] * p[i];
			if (d[v][j] < eps) {
				d[v][j] = 0.0;
			}
		}
	}

	printf("%.10lf\n", res);
	
	return 0;
}