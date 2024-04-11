#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 600;

int n, m;
int a[maxN][maxN], s[maxN][maxN];
int d1[maxN][maxN], d2[maxN][maxN], d3[maxN][maxN], d4[maxN][maxN];

inline int sum(int lx, int ly, int rx, int ry) {
	return s[rx][ry] - s[lx - 1][ry] - s[rx][ly - 1] + s[lx - 1][ly - 1];
}

int solve(int length) {
	int res = -1000000000;
	if (length == 3) {
		for (int i = 1; i + length - 1 <= n; ++i)
			for (int j = 1; j + length - 1 <= m; ++j) {
				d1[i][j] = sum(i, j, i + 2, j + 2) - a[i + 1][j] - a[i + 1][j + 1];
				d2[i][j] = sum(i, j, i + 2, j + 2) - a[i + 1][j + 1] - a[i + 1][j + 2];
			}
		for (int i = 1; i + length - 1 <= n; ++i)
			for (int j = 1; j + length - 1 <= m; ++j)
				res = max(res, d1[i][j]);
	} else {
		for (int i = 1; i + length - 1 <= n; ++i)
			for (int j = 1; j + length - 1 <= m; ++j) {
				d3[i][j] = d2[i + 2][j] + sum(i, j, i, j + length - 1) + sum(i + 1, j + length - 1, i + length - 1, j + length - 1) + a[i + length - 1][j + length - 2];
				d4[i][j] = d1[i][j + 2] + sum(i, j, i + length - 1, j) + sum(i + length - 1, j + 1, i + length - 1, j + length - 1) + a[i][j + 1];
				res = max(res, d3[i][j]);
			}
		for (int i = 1; i + length - 1 <= n; ++i)
			for (int j = 1; j + length - 1 <= m; ++j)
				d1[i][j] = d3[i][j], d2[i][j] = d4[i][j];
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];

	int res = -1000000000;
	for (int i = 3; i <= min(n, m); i += 2)
		res = max(res, solve(i));

	printf("%d\n", res);

	return 0;
}