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
int n, m;
int a[maxN];
int g[maxN][maxN];

void update(long long x, long long y, long long &p, long long &q) {
	if (y == 0) {
		return ;
	}
	if (x * q > y * p) {
		p = x;
		q = y;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u - 1][v - 1] = g[v - 1][u - 1] = w;
	}

	long long p = 0, q = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (g[i][j]) {
				update(a[i] + a[j], g[i][j], p, q);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				int cnt = (int)(g[i][j] > 0) + (int)(g[i][k] > 0) + (int)(g[k][j] > 0);
				if (cnt >= 2) {
					update(a[i] + a[j] + a[k], g[i][j] + g[i][k] + g[k][j], p, q);
				}
			}
		}
	}

	printf("%.10lf\n", (double)(p) / (double)(q));


	return 0;
}