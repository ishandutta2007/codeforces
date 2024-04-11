#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 60;
const int maxR = 6000;
int n, r;
int f[maxN], s[maxN], p[maxN];
double x[maxN], y[maxN];

double d[maxN][maxR];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &r);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &f[i], &s[i], &p[i]);
		x[i] = (double)(p[i]) / 100.0;
		y[i] = 1.0 - x[i];
	}

	double left_bound = 0.0, right_bound = 1e18;
	for (int t = 0; t < 150; ++t) {
		double m = (left_bound + right_bound) / 2.0;
		for (int i = 0; i <= r; ++i) {
			d[n][i] = 0.0;
		}
		for (int i = r + 1; i < maxR; ++i) {
			d[n][i] = m;
		}
		for (int i = n - 1; i >= 1; --i) {
			for (int j = 0; j <= r; ++j) {
				double v = x[i] * (d[i + 1][j + f[i]] + (double)(f[i])) + y[i] * (d[i + 1][j + s[i]] + (double)(s[i]));
				d[i][j] = min(m, v);
			}
			for (int j = r + 1; j < maxR; ++j) {
				d[i][j] = m;
			}
		}
		double score = x[0] * (d[1][f[0]] + (double)(f[0])) + y[0] * (d[1][s[0]] + (double)(s[0]));
		if (score > m) {
			left_bound = m;
		} else {
			right_bound = m;
		}
	}

	printf("%.10lf\n", (left_bound + right_bound) / 2.0);

	return 0;
}