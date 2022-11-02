#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

vector < vector < int > > g;
vector < int > order;
vector < int > used;
int n, m;
bool cycle;

void dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i]);
		} else {
			if (used[g[v][i]] == 1) {
				cycle = true;
			}
		}
	}

	used[v] = 2;

	if (v < m) {
		order.push_back(v);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	vector < vector < int > > a(n, vector < int > (m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	g.resize(m);
	int cnt = m;

	for (int i = 0; i < n; ++i) {
		vector < pair < int, int > > order;
		for (int j = 0; j < m; ++j) {
			if (a[i][j] != -1) {
				order.push_back(make_pair(2 * a[i][j], j));
			}
		}
		sort(order.begin(), order.end());

		vector < vector < int > > groups;
		vector < int > current;
		for (int j = 0; j <= order.size(); ++j) {
			if (j == order.size() || (j > 0 && order[j].first > order[j - 1].first)) {
				groups.push_back(current);
				current.clear();
			}
			if (j < order.size()) {
				current.push_back(order[j].second);
			}
		}
		for (int j = 0; j + 1 < groups.size(); ++j) {
			for (int k = 0; k < groups[j].size(); ++k) {
				g[groups[j][k]].push_back(cnt);
			}
			g.push_back(vector < int > ());
			for (int k = 0; k < groups[j + 1].size(); ++k) {
				g[cnt].push_back(groups[j + 1][k]);
			}
			++cnt;
		}
	}

	used.assign(cnt, 0);
	for (int i = 0; i < cnt; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}

	if (cycle) {
		printf("-1\n");
		return 0;
	}

	reverse(order.begin(), order.end());
	for (int i = 0; i < order.size(); ++i) {
		printf("%d ", order[i] + 1);
	}
	printf("\n");

	return 0;
}