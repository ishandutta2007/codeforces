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

const int maxN = 1100000;
const int inf = 1000000000;
int d[maxN], cnt[maxN];
vector < int > g[maxN], gr[maxN];
int n, m;
int s, t;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		gr[v].push_back(u);
	}
	scanf("%d%d", &s, &t);
	for (int i = 1; i <= n; ++i) {
		d[i] = inf;
		cnt[i] = g[i].size();
	}

	d[t] = 0;
	vector < int > level;
	level.push_back(t);
	while (level.size() > 0) {
		for (int i = 0; i < level.size(); ++i) {
			int v = level[i];
			for (int j = 0; j < gr[v].size(); ++j) {
				int u = gr[v][j];
				if (d[u] == inf) {
					--cnt[u];
					if (cnt[u] == 0) {
						d[u] = d[v];
						level.push_back(u);
					}
				}
			}
		}

		vector < int > nlevel;
		for (int i = 0; i < level.size(); ++i) {
			int v = level[i];
			for (int j = 0; j < gr[v].size(); ++j) {
				int u = gr[v][j];
				if (d[u] == inf) {
					d[u] = d[v] + 1;
					nlevel.push_back(u);
				}
			}
		}
		level = nlevel;
	}
	int res = d[s];
	if (res == inf) {
		res = -1;
	}
	printf("%d\n", res);

	return 0;
}