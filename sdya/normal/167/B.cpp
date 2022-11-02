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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210;
const double eps = 1e-14;
double d[maxN][maxN][2 * maxN];
int n, l, k;
double p[maxN];
int a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> l >> k;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		p[i] = (double)(x) / 100.0;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	d[0][0][maxN + k] = 1.0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k < 2 * maxN; ++k) {
				if (d[i][j][k] < eps) {
					continue;
				}
				int nk = k;
				if (a[i] > 0) {
					nk += a[i];
				} else {
					--nk;
				}
				if (nk >= 2 * maxN) {
					nk = 2 * maxN - 1;
				}
				d[i + 1][j][k] += d[i][j][k] * (1.0 - p[i]);
				d[i + 1][j + 1][nk] += d[i][j][k] * p[i];
			}
		}
	}

	double res = 0.0;
	for (int i = l; i <= n; ++i) {
		for (int j = maxN; j < 2 * maxN; ++j) {
			res += d[n][i][j];
		}
	}
	printf("%.10lf\n", res);


	return 0;
}