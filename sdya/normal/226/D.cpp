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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
int a[maxN][maxN], n, m;

int getCol(int k) {
	int res = 0;
	for (int i = 0; i < n; ++i) {
		res += a[i][k];
	}
	return res;
}

int getRow(int k) {
	int res = 0;
	for (int i = 0; i < m; ++i) {
		res += a[k][i];
	}
	return res;
}

int cols[maxN], rows[maxN];

void switchRow(int k) {
	rows[k] ^= 1;
	for (int i = 0; i < m; ++i) {
		a[k][i] = -a[k][i];
	}
}

void switchCol(int k) {
	cols[k] ^= 1;
	for (int i = 0; i < n; ++i) {
		a[i][k] = -a[i][k];
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	while (true) {
		bool isOk = true;
		for (int i = 0; i < n; ++i) {
			if (getRow(i) < 0) {
				isOk = false;
				break;
			}
		}
		for (int i = 0; i < m && isOk; ++i) {
			if (getCol(i) < 0) {
				isOk = false;
			}
		}
		if (isOk) {
			break;
		}

		for (int i = 0; i < n; ++i) {
			if (getRow(i) < 0) {
				switchRow(i);
			}
		}
		for (int i = 0; i < m; ++i) {
			if (getCol(i) < 0) {
				switchCol(i);
			}
		}
	}

	int cnt = count(rows, rows + n, 1);
	printf("%d", cnt);
	for (int i = 0; i < n; ++i) {
		if (rows[i]) {
			printf(" %d", i + 1);
		}
	}
	printf("\n");

	cnt = count(cols, cols + m, 1);
	printf("%d", cnt);
	for (int i = 0; i < m; ++i) {
		if (cols[i]) {
			printf(" %d", i + 1);
		}
	}
	printf("\n");

	return 0;
}