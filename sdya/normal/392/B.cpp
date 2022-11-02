#define _CRT_SECURE_NO_WARNINGS
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

long long t[3][3], a[3][3];

const long long maxN = 45;
long long d[maxN][3][3];

int getUnused(int x, int y) {
	if (x != 0 && y != 0) {
		return 0;
	}
	if (x != 1 && y != 1) {
		return 1;
	}
	return 2;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> t[i][j];
			d[1][i][j] = t[i][j];
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int k = getUnused(i, j);
			d[1][i][j] = min(d[1][i][j], t[i][k] + t[k][j]);
		}
	}

	for (int n = 2; n < maxN; ++n) {
		for (int x = 0; x < 3; ++x) {
			for (int y = 0; y < 3; ++y) {
				if (x == y) {
					d[n][x][y] = 0;
					continue;
				}
				int z = getUnused(x, y);
				long long u = min(d[n - 1][x][z], d[n - 1][x][y] + d[n - 1][y][z]);
				long long v = min(d[n - 1][z][y], d[n - 1][z][x] + d[n - 1][x][y]);
				d[n][x][y] = u + t[x][y] + v;

				long long xy = min(d[n - 1][x][y], d[n - 1][x][z] + d[n - 1][z][y]);
				long long yx = min(d[n - 1][y][x], d[n - 1][y][z] + d[n - 1][z][x]);

				d[n][x][y] = min(d[n][x][y], xy + t[x][z] + yx + t[z][y] + xy);
			}
		}
	}

	int n;
	cin >> n;
	cout << d[n][0][2] << endl;

	return 0;
}