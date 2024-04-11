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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const long long inf = 1000000000000000000LL;
int n;
long long a[3][maxN];
long long s[maxN];

long long d[maxN][3];

void update(int i, int j, long long value) {
	//cerr << i << " " << j << endl;
	d[i][j] = max(d[i][j], value);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n; ++j) {
			int v;
			scanf("%d", &v);
			a[i][j] = v;
		}
	}
	for (int i = 0; i < n; ++i) {
		s[i] = a[0][i] + a[1][i] + a[2][i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			d[i][j] = -inf;
		}
	}

	d[0][0] = a[0][0];
	d[0][1] = a[0][0] + a[1][0];
	d[0][2] = s[0];

	if (n > 1) {
		update(1, 2, s[0] + s[1]);
	}

	for (int i = 0; i < n; ++i) {
		update(i + 1, 0, d[i][0] + a[0][i + 1]);
		update(i + 1, 1, d[i][0] + a[0][i + 1] + a[1][i + 1]);
		update(i + 1, 2, d[i][0] + s[i + 1]);

		update(i + 1, 1, d[i][1] + a[1][i + 1]);
		update(i + 1, 0, d[i][1] + a[1][i + 1] + a[0][i + 1]);
		update(i + 1, 2, d[i][1] + a[1][i + 1] + a[2][i + 1]);

		update(i + 1, 2, d[i][2] + a[2][i + 1]);
		update(i + 1, 1, d[i][2] + a[2][i + 1] + a[1][i + 1]);
		update(i + 1, 0, d[i][2] + s[i + 1]);

		update(i + 2, 2, d[i][0] + s[i + 1] + s[i + 2]);
		update(i + 2, 0, d[i][2] + s[i + 1] + s[i + 2]);
	}

	cout << d[n - 1][2] << endl;


	return 0;
}