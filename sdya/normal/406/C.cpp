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
int n, m;
vector < int > g[maxN], h[maxN], hr[maxN];
int d[maxN], s[maxN];

int used[maxN];

void dfs(int v, int p = -1) {
	used[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			h[v].push_back(g[v][i]);
			dfs(g[v][i], v);
		} else {
			if (p != g[v][i] && used[g[v][i]] == 1) {
				hr[g[v][i]].push_back(v);
			}
		}
	}
	used[v] = 2;
}

void precalc(int v) {
	s[v] = hr[v].size();
	for (int i = 0; i < h[v].size(); ++i) {
		precalc(h[v][i]);
		s[v] += s[h[v][i]] + 1;
	}
}

struct Edge {
	int x, y, z;
	Edge(int x, int y, int z) : x(x), y(y), z(z) {}
	Edge() {}
	void print() {
		printf("%d %d %d\n", x + 1, y + 1, z + 1);
	}
};

vector < Edge > res;

bool solve(int v) {
	if (s[v] % 2 == 1) {
		return false;
	}

	vector < int > odd;
	for (int i = 0; i < h[v].size(); ++i) {
		int u = h[v][i];
		if (s[u] % 2 == 0) {
			solve(u);
			hr[v].push_back(u);
		} else {	
			if (hr[u].size() > 0) {
				res.push_back(Edge(v, u, hr[u].back()));
				hr[u].pop_back();
				--s[u];
				solve(u);
			} else {
				hr[u].push_back(v);
				for (int j = 0; j < h[u].size(); ++j) {
					int w = h[u][j];
					if (s[w] % 2 == 1) {
						hr[w].push_back(u);
						++s[w];
						solve(w);
					} else {
						solve(w);
						hr[u].push_back(w);
					}
				}
				for (int j = 0; j < hr[u].size(); j += 2) {
					res.push_back(Edge(hr[u][j], u, hr[u][j + 1]));
				}
			}
		}
	}

	for (int i = 0; i < hr[v].size(); i += 2) {
		res.push_back(Edge(hr[v][i], v, hr[v][i + 1]));
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
		++d[u];
		++d[v];
	}

	vector < int > roots;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			roots.push_back(i);
			dfs(i);
			precalc(i);
		}
	}

	for (int i = 0; i < roots.size(); ++i) {
		if (!solve(roots[i])) {
			printf("No solution\n");
			return 0;
		}
	}

	for (int i = 0; i < res.size(); ++i) {
		res[i].print();
	}

	return 0;
}