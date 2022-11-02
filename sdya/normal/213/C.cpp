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

const int maxN = 310;
const int inf = 1000000000;
int d[2][maxN][maxN];
int n, a[maxN][maxN], s[maxN][maxN];

void setInf(int d[maxN][maxN]) {
	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			d[i][j] = -inf;
		}
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	int u = 0, v = 1;
	setInf(d[u]);

	d[u][0][0] = 0;
	for (int step = 0; step < n; ++step, swap(u, v)) {
		setInf(d[v]);
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				int value = d[u][i][j];
				value += a[step][i] + a[step][j];
				if (i == j) {
					value -= a[step][i];
				}
				d[v][i][j] = max(d[v][i][j], value);
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				if (i < j) {
					int value = d[v][i][j];
					value += a[step][i + 1];
					if (i + 1 == j) {
						value -= a[step][i + 1];
					}
					d[v][i + 1][j] = max(d[v][i + 1][j], value);
				}
				if (i == j && i + 1 < n) {
					d[v][i + 1][j + 1] = max(d[v][i + 1][j + 1], d[v][i][j] + a[step][i + 1]); 
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				if (j + 1 < n) {
					d[v][i][j + 1] = max(d[v][i][j + 1], d[v][i][j] + a[step][j + 1]); 
				}
			}
		}
	}

	printf("%d\n", d[u][n - 1][n - 1]);


	return 0;
}