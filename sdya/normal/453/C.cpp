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
int n, m;
vector < int > g[maxN];
int c[maxN], p[maxN];

int find(int v) {
	if (p[v] == v) {
		return v;
	}
	return p[v] = find(p[v]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (rand() % 2 == 0) {
		p[u] = v;
	} else {
		p[v] = u;
	}
}

bool used[maxN];

void getComp(int u, vector < int > &c) {
	used[u] = true;
	c.push_back(u);
	for (int i = 0; i < g[u].size(); ++i) {
		if (!used[g[u][i]]) {
			getComp(g[u][i], c);
		}
	}
}

pair < bool, vector < int > > solve(int v, int p = -1) {
	vector < pair < int, pair < bool, vector < int > > > > children;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] == p) {
			continue;
		}
		pair < bool, vector < int > > r = solve(g[v][i], v);
		if (r.second.size() > 0) {
			children.push_back(make_pair(g[v][i], r));
		}
	}

	if (children.size() == 0) {
		if (c[v] == 0) {
			return make_pair(true, vector < int > ());
		}
		return make_pair(true, vector < int > (1, v));
	}

	vector < int > r;
	r.push_back(v);
	int cnt = 1;
	for (int i = 0; i < children.size(); ++i) {
		int u = children[i].first;
		vector < int > &p = children[i].second.second;
		bool correct = children[i].second.first;

		if (correct) {
			for (int j = 0; j < p.size(); ++j) {
				r.push_back(p[j]);
			}
			r.push_back(v);
			++cnt;
		} else {
			r.push_back(u);
			r.push_back(v);
			++cnt;
			for (int j = 0; j < p.size(); ++j) {
				r.push_back(p[j]);
			}
			r.push_back(v);
			++cnt;
		}
	}

	if (cnt % 2 == c[v]) {
		return make_pair(true, r);
	}

	if (p == -1) {
		r.pop_back();
		return make_pair(true, r);
	}
	return make_pair(false, r);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	vector < pair < int, int > > edges;
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges.push_back(make_pair(u - 1, v - 1));
	}

	for (int i = 0; i < n; ++i) {
		scanf("%d", &c[i]);
		p[i] = i;
	}
	
	for (int i = 0; i < edges.size(); ++i) {
		int u = edges[i].first;
		int v = edges[i].second;
		if (find(u) != find(v)) {
			g[u].push_back(v);
			g[v].push_back(u);
			merge(u, v);
		}
	}

	int comps = 0;
	vector < int > heads;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			++comps;
			vector < int > cc;
			getComp(i, cc);

			bool needed = false;
			for (int j = 0; j < cc.size(); ++j) {
				if (c[cc[j]] != 0) {
					needed = true;
				}
			}
			if (needed) {
				heads.push_back(i);
			}
		}
	}

	if (heads.size() > 1) {
		printf("-1\n");
		return 0;
	}
	if (heads.size() == 0) {
		printf("0\n");
		return 0;
	}

	vector < int > r = solve(heads[0]).second;
	printf("%d\n", r.size());
	for (int i = 0; i < r.size(); ++i) {
		printf("%d ", r[i] + 1);
	}
	printf("\n");

	return 0;
}