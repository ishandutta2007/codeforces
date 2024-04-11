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

const int maxN = 110000;
int n, t;
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

	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n - 1; ++i) {
		int v;
		scanf("%d", &v);
		g[i].push_back(i + v);
	}
	dfs(1);

	if (used[t]) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	
	return 0;
}