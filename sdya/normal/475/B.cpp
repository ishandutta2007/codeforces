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

const int maxN = 22;
int g[maxN * maxN][maxN * maxN];
int n, m;
string a, b;

bool isValid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	cin >> a >> b;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i] == '<' && isValid(i, j - 1)) {
				g[i * m + j][i * m + (j - 1)] = 1;
			}
			if (a[i] == '>' && isValid(i, j + 1)) {
				g[i * m + j][i * m + (j + 1)] = 1;
			}
			if (b[j] == '^' && isValid(i - 1, j)) {
				g[i * m + j][(i - 1) * m + j] = 1;
			}
			if (b[j] == 'v' && isValid(i + 1, j)) {
				g[i * m + j][(i + 1) * m + j] = 1;
			}
		}
	}

	int r = n * m;
	for (int i = 0; i < r; ++i) {
		g[i][i] = 1;
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < r; ++j) {
			for (int k = 0; k < r; ++k) {
				g[j][k] |= (g[j][i] & g[i][k]);
			}
		}
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < r; ++j) {
			if (g[i][j] == 0) {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");

	return 0;
}