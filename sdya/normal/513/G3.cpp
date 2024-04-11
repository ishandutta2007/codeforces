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
int u, v;
double d[2][maxN][maxN];
double sa[2][maxN][maxN], sb[2][maxN][maxN];
int c[maxN];

void calcSums() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			sa[0][i][j] = d[u][j][i] + sa[0][i][j - 1];
			sb[0][i][j] = d[u][j][i] * (double)(j) + sb[0][i][j - 1];
			sa[1][i][j] = d[u][i][j] + sa[1][i][j - 1];
			sb[1][i][j] = d[u][i][j] * (double)(j) + sb[1][i][j - 1];
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 1; i < maxN; ++i) {
		c[i] = (i * (i + 1)) / 2;
	}
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	u = 0, v = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (a[i] < a[j]) {
				d[u][i][j] = 1.0;
			} else {
				d[u][j][i] = 1.0;
			}
		}
	}
	double p = 2. / (double)(n * (n + 1));
	for (int steps = 0; steps < min(875, k); ++steps, swap(u, v)) {
		calcSums();
		memset(d[v], 0, sizeof(d[v]));
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j) {
					continue;
				}
				bool s = (i > j);
				int oldi = i, oldj = j;
				if (s) {
					swap(i, j);
				}
				{
					if (i <= j - i) {
						d[v][oldi][oldj] += (sa[s][j][j - i] - sa[s][j][i - 1]) * (double)(i);
					} else {
						d[v][oldi][oldj] += (sa[s][j][i - 1] - sa[s][j][j - i - 1]) * (double)(j - i);
					}
					{
						int l = max(j - i + 1, i) - 1;
						d[v][oldi][oldj] += (sa[s][j][j - 1] - sa[s][j][l]) * (double)(j) - (sb[s][j][j - 1] - sb[s][j][l]);
						int r = min(i - 1, j - i - 1);
						d[v][oldi][oldj] += sb[s][j][r];
					}
					if (n + i + 1 - j <= j) {
						d[v][oldi][oldj] += (sa[1 - s][i][j] - sa[1 - s][i][n + i - j]) * (double)(n - j + 1);
					} else {
						d[v][oldi][oldj] += (sa[1 - s][i][n + i + 1 - j] - sa[1 - s][i][j]) * (double)(j - i);
					}
					{
						int r = min(j, n + i + 1 - j - 1);
						d[v][oldi][oldj] += (sa[1 - s][i][r] - sa[1 - s][i][i - 1]) * (double)(-i) + (sb[1 - s][i][r] - sb[1 - s][i][i - 1]);
						int l = max(j + 1, n + i + 1 - j + 1);
						d[v][oldi][oldj] += (sa[1 - s][i][n] - sa[1 - s][i][l - 1]) * (double)(n + 1) - (sb[1 - s][i][n] - sb[1 - s][i][l - 1]); 
					}
				}
				if (s) {
					swap(i, j);
				}
				if (i < j) {
					for (int sum = 1 + j; sum <= i + n; ++sum) {
						int l = sum > n ? sum - n : 1;
						int r = sum < i + j ? sum - j : i;
						if (l <= r) {
							d[v][i][j] += (double)(r - l + 1) * d[u][sum - i][sum - j];
							d[v][j][i] += (double)(r - l + 1) * d[u][sum - j][sum - i];
						} else {
							break;
						}
					}
				}
				{
					int ways = c[min(i, j) - 1] + c[max(i, j) - min(i, j) - 1] + c[n - max(i, j)];
					d[v][i][j] += (double)(ways) * d[u][i][j];
				}
				d[v][i][j] *= p;
			}
		}
	}
	double res = 0.0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			res += d[u][i][j];
		}
	}
	printf("%.10lf\n", res);

	return 0;
}