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

const int maxN = 510;
int n, k;
int a[maxN];
bool d[2][maxN][maxN];

void set0(bool d[maxN][maxN]) {
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; i + j <= k; ++j) {
			d[i][j] = false;
		}
	}
}

bool c[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	int u = 0, v = 1;
	set0(d[u]);
	d[u][0][0] = true;

	for (int t = 0; t < n; ++t, swap(u, v)) {
		set0(d[v]);

		for (int i = 0; i <= k; ++i) {
			for (int j = 0; i + j <= k; ++j) {
				if (!d[u][i][j]) {
					continue;
				}
				d[v][i][j] = true;
				if (i + a[t] < maxN) {
					d[v][i + a[t]][j] = true;
				}
				if (j + a[t] < maxN) {
					d[v][i][j + a[t]] = true;
				}
			}
		}
	}

	for (int i = 0; i <= k; ++i) {
		if (d[u][i][k - i]) {
			c[i] = true;
			c[k - i] = true;
		}
	}

	int res = 0;
	for (int i = 0; i <= k; ++i) {
		if (c[i]) {
			++res;
		}
	}
	printf("%d\n", res);
	for (int i = 0; i <= k; ++i) {
		if (c[i]) {
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}