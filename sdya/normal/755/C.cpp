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

const int maxN = 11000;
int n;
int p[maxN];
vector < int > g[maxN];

bool used[maxN];

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i]);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
		g[i].push_back(p[i]);
		g[p[i]].push_back(i);
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			++res;
			dfs(i);
		}
	}

	printf("%d\n", res);

	return 0;
}