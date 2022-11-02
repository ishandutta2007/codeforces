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

const int maxN = 510;
int n, m, b, P;
int a[maxN];

int d[2][maxN][maxN];

void set0(int d[maxN][maxN]) {
	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			d[i][j] = 0;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> b >> P;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int u = 0, v = 1;
	set0(d[u]);
	d[u][0][0] = 1 % P;
	for (int step = 0; step < n; ++step, swap(u, v)) {
		set0(d[v]);
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= b; ++j) {
				if (d[u][i][j] == 0) {
					continue;
				}
				d[v][i][j] += d[u][i][j];
				if (d[v][i][j] >= P) {
					d[v][i][j] -= P;
				}
			}
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = a[step]; j <= b; ++j) {
				d[v][i][j] += d[v][i - 1][j - a[step]];
				if (d[v][i][j] >= P) {
					d[v][i][j] -= P;
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i <= b; ++i) {
		res += d[u][m][i];
		if (res >= P) {
			res -= P;
		}
	}
	cout << res << endl;

	return 0;
}