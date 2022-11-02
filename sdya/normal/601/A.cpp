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

const int maxN = 440;

int g[maxN][maxN];
int n, m;

int d[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			g[i][j] = (int)(i != j);
		}
	}

	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		g[x][y] = g[y][x] = 2;
	}

	int needed = 3 - g[0][n - 1];
	
	for (int i = 0; i < n; ++i) {
		d[i] = -1;
	}

	d[0] = 0;
	queue < int > q;
	q.push(0);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < n; ++i) {
			if (g[v][i] == needed && d[i] == -1) {
				d[i] = d[v] + 1;
				q.push(i);
			}
		}
	}

	printf("%d\n", d[n - 1]);

	return 0;
}