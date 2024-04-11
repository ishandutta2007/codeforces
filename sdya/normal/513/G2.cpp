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

const int maxN = 110;
int n, k, a[maxN];

void solve() {
	vector < vector < double > > d[2];
	int u = 0, v = 1;
	d[u].assign(maxN, vector < double > (maxN, 0.0));
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (a[i] < a[j]) {
				d[u][i][j] = 1.0;
			} else {
				d[u][j][i] = 1.0;
			}
		}
	}
	double p = 2.0 / (double)(n * (n + 1));
	for (int steps = 0; steps < k; ++steps, swap(u, v)) {
		d[v].assign(maxN, vector < double > (maxN, 0.0));
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j) {
					continue;
				}
				for (int a = 1; a <= n; ++a) {
					for (int b = a; b <= n; ++b) {
						int ni = i;
						if (a <= i && i <= b) {
							ni = a + b - i;
						}
						int nj = j;
						if (a <= j && j <= b) {
							nj = a + b - j;
						}
						d[v][ni][nj] += p * d[u][i][j];
					}
				}
			}
		}
		/*for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				printf("%d %d, %.10lf\n", i, j, d[v][i][j] / p);
			}
		}*/
	}
	double res = 0.0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			res += d[u][i][j];
		}
	}
	printf("%.10lf\n", res);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	solve();

	return 0;
}