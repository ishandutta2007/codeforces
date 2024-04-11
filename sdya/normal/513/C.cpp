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

const int maxN = 10;
int l[maxN], r[maxN];
int n;

double d[maxN][maxN][maxN];

double calc(int price) {
	memset(d, 0, sizeof(d));
	d[0][0][0] = 1.0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k <= n; ++k) {
				double p = 1. / (double)(r[i] - l[i] + 1);
				if (l[i] <= price && price <= r[i]) {
					d[i + 1][j + 1][k] += d[i][j][k] * p;
				}

				int bound = max(l[i], price + 1);
				if (bound <= r[i]) {
					d[i + 1][j][k + 1] += d[i][j][k] * p * (double)(r[i] - bound + 1);
				}

				bound = min(price - 1, r[i]);
				if (l[i] <= bound) {
					d[i + 1][j][k] += d[i][j][k] * p * (double)(bound - l[i] + 1);
				}
			}
		}
	}
	double res = 0.0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 1; ++j) {
			if ((j == 0 && i > 1) || j == 1) {
				res += d[n][i][j];
			}
		}
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
	}

	double res = 0.0;
	for (int price = 1; price <= 10000; ++price) {
		res += (double)(price) * calc(price);
	}
	printf("%.10lf\n", res);

	return 0;
}