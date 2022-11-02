#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int color[maxN];
int n, m;
vector < int > g[maxN], gr[maxN];

bool used1[maxN], used2[maxN];

void dfs1(int v) {
	if (used1[v]) return ;
	used1[v] = true;

	if (color[v] == 1) return ;

	for (int i = 0; i < gr[v].size(); ++i)
		dfs1(gr[v][i]);
}

void dfs2(int v) {
	if (used2[v]) return ;
	used2[v] = true;

	for (int i = 0; i < g[v].size(); ++i)
		if (color[g[v][i]] != 1) dfs2(g[v][i]);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &color[i]);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		gr[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i)
		if (color[i] == 2 && !used1[i]) dfs1(i);

	for (int i = 1; i <= n; ++i)
		if (color[i] == 1 && !used2[i]) dfs2(i);

	for (int i = 1; i <= n; ++i)
		if (used1[i] && used2[i]) printf("1\n"); else printf("0\n");

	return 0;
}