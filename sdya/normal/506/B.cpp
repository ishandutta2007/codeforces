#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <string>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, m;
vector<int> g[maxN], gr[maxN];
vector<char> used;
vector<int> order, component;
 
void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}
 
void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}

int comp[maxN], comp_cnt;
int comp_size[maxN];
vector < int > h[maxN];
bool visited[maxN];

void dfs3 (int v) {
	visited[v] = true;
	component.push_back(v);
	for (int i = 0; i < h[v].size(); ++i) {
		if (!visited[h[v][i]]) {
			dfs3(h[v][i]);
		}
	}
}
 
void solve() {
	comp_cnt = 0;
	used.assign (n, false);
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs1 (i);
	used.assign (n, false);
	int res = 0;
	for (int i=0; i<n; ++i) {
		int v = order[n-1-i];
		if (!used[v]) {
			component.clear();
			dfs2 (v);
			++comp_cnt;
			for (int j = 0; j < component.size(); ++j) {
				comp[component[j]] = comp_cnt;
			}
			comp_size[comp_cnt] = component.size();
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			if (comp[i] != comp[g[i][j]]) {
				int x = comp[i];
				int y = comp[g[i][j]];
				h[x].push_back(y);
				h[y].push_back(x);
			}
		}
	}

	for (int i = 1; i <= comp_cnt; ++i) {
		if (!visited[i]) {
			component.clear();
			dfs3(i);
			bool isOk = true;
			for (int j = 0; j < component.size(); ++j) {
				if (comp_size[component[j]] > 1) {
					isOk = false;
				}
			}
			if (isOk) {
				res += component.size() - 1;
			} else {
				for (int j = 0; j < component.size(); ++j) {
					res += comp_size[component[j]];
				}
			}
		}
	}
	printf("%d\n", res);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		gr[v].push_back(u);
	}
	solve();

	return 0;
}