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
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int P = 1000000007;
int n, m, x;

const int maxK = 400;
int d[2][maxK][maxK];

void set0(int d[maxK][maxK]) {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			d[i][j] = 0;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &x);
	if (n > m) {
		printf("0\n");
		return 0;
	}

	int u = 0, v = 1;
	set0(d[u]);
	d[u][0][0] = 1;

	for (int steps = 0; steps < m; ++steps, swap(u, v)) {
		set0(d[v]);
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= i; ++j) {
				if (d[u][i][j] == 0) {
					continue;
				}
				int sa = (steps == x - 1 ? 1 : 0);
				for (int a = sa; a < 2; ++a) {
					for (int b = 0; b < 2 && b <= j; ++b) {
						d[v][i + a][j - b + a] += d[u][i][j];
						if (d[v][i + a][j - b + a] >= P) {
							d[v][i + a][j - b + a] -= P;
						}
					}
				}
			}
		}
	}

	long long res = (d[u][n][0] + d[u][n][1]) % P;
	for (int i = 1; i <= n; ++i) {
		res = (res * (long long)(i)) % (long long)(P);
	}
	cout << res << endl;

	return 0;
}