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
int color[maxN];
vector < int > g[maxN];
int n, m;

void dfs(int v, int c) {
	color[v] = c;
	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		if (color[u] != 0 && color[u] == c) {
			printf("-1\n");
			exit(0);
		}
		if (color[u] == 0) {
			dfs(u, 3 - c);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		if (color[i] == 0) {
			dfs(i, 1);
		}
	}

	vector < int > a, b;
	for (int i = 1; i <= n; ++i) {
		if (color[i] == 1) {
			a.push_back(i);
		} else {
			b.push_back(i);
		}
	}

	printf("%d\n", a.size());
	for (int i = 0; i < a.size(); ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("%d\n", b.size());
	for (int i = 0; i < b.size(); ++i) {
		printf("%d ", b[i]);
	}
	printf("\n");

	return 0;
}