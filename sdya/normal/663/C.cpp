#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;

int n, m;
vector < pair < int, int > > g[maxN];

int c[maxN];

bool dfs(int v, int cur, int color, vector < int > &comp) {
	c[v] = cur;
	comp.push_back(v);

	for (int i = 0; i < g[v].size(); ++i) {
		int j = g[v][i].first;
		int w = g[v][i].second;

		if (w == color) {
			if (c[j] != -1 && c[j] != cur) {
				return false;
			}
			if (c[j] == -1) {
				if (!dfs(j, cur, color, comp)) {
					return false;
				}
			}
		} else {
			if (c[j] != -1 && c[j] == cur) {
				return false;
			}
			if (c[j] == -1) {
				if (!dfs(j, 1 - cur, color, comp)) {
					return false;
				}
			}
		}
	}
	return true;
}

bool solve(int color, vector < int > &res) {
	for (int i = 0; i < n; ++i) {
		c[i] = -1;
	}

	for (int i = 0; i < n; ++i) {
		if (c[i] != -1) {
			continue;
		}

		vector < int > comp;
		bool good = dfs(i, 1, color, comp);
		if (!good) {
			return false;
		}

		vector < int > z, o;
		for (int j = 0; j < comp.size(); ++j) {
			if (c[comp[j]] == 0) {
				z.push_back(comp[j]);
			} else {
				o.push_back(comp[j]);
			}
		}
		vector < int > added = z;
		if (o.size() < z.size()) {
			added = o;
		}
		for (int j = 0; j < added.size(); ++j) {
			res.push_back(added[j]);
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		char c;
		scanf("%d %d %c", &u, &v, &c);
		--u;
		--v;
		g[u].push_back(make_pair(v, c == 'B' ? 1 : 2));
		g[v].push_back(make_pair(u, c == 'B' ? 1 : 2));
	}

	vector < int > b, r;
	bool canb = solve(1, b);
	bool canr = solve(2, r);

	bool can = false;
	vector < int > res;
	if (canb && (!can || res.size() > b.size())) {
		can = true;
		res = b;
	}
	if (canr && (!can || res.size() > r.size())) {
		can = true;
		res = r;
	}

	if (!can) {
		printf("-1\n");
	} else {
		printf("%d\n", res.size());
		for (int i = 0; i < res.size(); ++i) {
			printf("%d ", res[i] + 1);
		}
		printf("\n");
	}


	return 0;
}