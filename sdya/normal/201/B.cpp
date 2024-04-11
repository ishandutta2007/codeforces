#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
int n, m;
int c[maxN][maxN];

long long d[maxN];

long long calcX(int &x) {
	for (int i = 0; i < n; ++i) {
		d[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			d[i] += (long long)(c[i][j]);
		}
	}

	long long best = 9000000000000000000LL;
	for (int i = 0; i <= n; ++i) {
		long long cur = 0;
		for (int j = 0; j < n; ++j) {
			long long p = 4 * i - 4 * j - 2;
			cur += p * p * d[j];
		}
		if (cur < best) {
			best = cur;
			x = i;
		}
	}
	return best;
}

long long calcY(int &y) {
	for (int i = 0; i < m; ++i) {
		d[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			d[j] += (long long)(c[i][j]);
		}
	}

	long long best = 9000000000000000000LL;
	for (int i = 0; i <= m; ++i) {
		long long cur = 0;
		for (int j = 0; j < m; ++j) {
			long long p = 4 * i - 4 * j - 2;
			cur += p * p * d[j];
		}
		if (cur < best) {
			best = cur;
			y = i;
		}
	}
	return best;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &c[i][j]);
		}
	}

	int x, y;
	long long rx = calcX(x);
	long long ry = calcY(y);
	cout << rx + ry << endl;
	cout << x << " " << y << endl;

	return 0;
}