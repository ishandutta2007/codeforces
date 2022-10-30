#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
const int maxL = 25;
const int maxD = 35;
char s[maxN][maxL];
int n, m;
int a[maxN][maxL], b[maxN][maxL];
int da[maxN][maxD], db[maxN][maxD];

int get(int x, int y) {
	if (x == -1) {
		return 0;
	}
	for (int i = m; i >= 0; --i) {
		if (b[x][i] == a[y][i]) {
			return i;
		}
	}
	return 0;
}

int calc(int i, int j) {
	if (j + 1 < maxD && da[i][j + 1] != -1) {
		return da[i][j + 1];
	}
	if (i - j < maxD && db[i][i - j] != -1) {
		return db[i][i - j];
	}

	if (!(j + 1 < maxD || i - j < maxD)) {
		return 1000000000;
	}

	if (j == -1 && i == 0) {
		return m;
	}

	int res = 1000000000;
	if (i > j + 1) {
		res = min(res, calc(i - 1, j) + m - get(i - 1, i));
	} else {
		for (int k = j - 1; k >= j - maxD && k >= -1; --k) {
			res = min(res, calc(i - 1, k) + m - get(k, i));
		}
	}

	if (j + 1 < maxD) {
		da[i][j + 1] = res;
	}
	if (i - j < maxD) {
		db[i][i - j] = res;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
	}
	m = strlen(s[0]);
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			a[i][j] = a[i][j - 1] * 2 + s[i][j - 1] - '0';
		}

		int p = 1;
		int k = 1;
		for (int j = m - 1; j >= 0; --j, ++k, p += p) {
			b[i][k] = p * (s[i][j] - '0') + b[i][k - 1];
		}
	}

	memset(da, -1, sizeof(da));
	memset(db, -1, sizeof(db));

	int res = 1000000000;
	for (int i = n - maxD; i + 1 < n; ++i) {
		if (i >= -1) {
			res = min(res, calc(n - 1, i));
		}
	}
	for (int i = -1; i + 1 < maxD && i < n - 1; ++i) {
		res = min(res, calc(n - 1, i));
	}

	printf("%d\n", res);
	
	return 0;
}