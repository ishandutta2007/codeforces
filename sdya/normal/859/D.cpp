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

const int maxN = 200;
const int maxK = 20;
int k, n;
int p[maxN][maxN];

long double d[maxK][maxN];
long double e[maxK][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &k);
	int n = (1 << k);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &p[i][j]);
		}
	}

	for (int x = 0; x < n; x += 2) {
		int y = (x ^ 1);
		d[k][x] = (long double)(p[x][y]) / 100.0;
		d[k][y] = (long double)(p[y][x]) / 100.0;
	}

	int step = 2;
	for (int i = k - 1; i >= 1; --i) {
		step *= 2;
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < n; ++y) {
				if (x / step != y / step) {
					continue;
				}
				if (x / (step / 2) == y / (step / 2)) {
					continue;
				}
				d[i][x] += d[i + 1][x] * d[i + 1][y] * (long double)(p[x][y]) / 100.0;
			}
		}
	}

	for (int x = 0; x < n; ++x) {
		e[k][x] = d[k][x];
	}

	int prize = 1;
	step = 2;
	for (int i = k - 1; i >= 1; --i) {
		prize *= 2;
		step *= 2;
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < n; ++y) {
				if (x / step != y / step) {
					continue;
				}
				if (x / (step / 2) == y / (step / 2)) {
					continue;
				}

				e[i][x] = max(e[i][x], e[i + 1][x] + e[i + 1][y] + (long double)(prize) * d[i][x]);
			}
		}
	}

	long double res = 0.0;
	for (int i = 0; i < n; ++i) {
		res = max(res, e[1][i]);
	}

	printf("%.10lf\n", (double)(res));

	return 0;
}