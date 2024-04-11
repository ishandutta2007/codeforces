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

const int maxN = 110000;
vector < int > g[maxN];
int n;
int a[maxN], b[maxN];

bool used[maxN];

vector < int > p;

int dfs(int v, int depth = 0, int odd = 0, int even = 0) {
	used[v] = true;
	int value = a[v];
	if (odd && depth % 2 == 1) {
		value ^= 1;
	}
	if (even && depth % 2 == 0) {
		value ^= 1;
	}

	int res = 0;
	if (value != b[v]) {
		++res;
		if (depth % 2 == 0) {
			even ^= 1;
		} else {
			odd ^= 1;
		}
		p.push_back(v + 1);
	}
	for (int i = 0; i < g[v].size(); ++i) {
		if (used[g[v][i]]) {
			continue;
		}
		res += dfs(g[v][i], depth + 1, odd, even);
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}

	printf("%d\n", dfs(0));
	for (int i = 0; i < p.size(); ++i) {
		printf("%d\n", p[i]);
	}

	return 0;
}