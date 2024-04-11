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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const int maxD = 250;
int n, m, h, t;
vector < int > g[maxN];
int cnt[maxN];

void build(int u, int v) {
	for (int i = 0; i < g[u].size(); ++i) {
		if (g[u][i] != v) {
			++cnt[g[u][i]];
		}
	}
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != u) {
			++cnt[g[v][i]];
		}
	}

	vector < int > common;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] == 2) {
			common.push_back(i);
		}
	}

	vector < int > H, T;
	for (int i = 0; i < g[u].size() && h > 0; ++i) {
		if (g[u][i] != v && cnt[g[u][i]] == 1) {
			H.push_back(g[u][i]);
			--h;
		}
	}

	for (int i = 0; i < g[v].size() && t > 0; ++i) {
		if (g[v][i] != u && cnt[g[v][i]] == 1) {
			T.push_back(g[v][i]);
			--t;
		}
	}

	for (int i = 0; i < h; ++i) {
		H.push_back(common[i]);
	}
	for (int i = h; i < h + t; ++i) {
		T.push_back(common[i]);
	}
	printf("YES\n");
	printf("%d %d\n", u, v);
	for (int i = 0; i < H.size(); ++i) {
		printf("%d ", H[i]);
	}
	printf("\n");
	for (int i = 0; i < T.size(); ++i) {
		printf("%d ", T[i]);
	}
	printf("\n");
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &h, &t);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		sort(g[i].begin(), g[i].end());
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			int u = i;
			int v = g[i][j];

			if (g[u].size() >= maxD && g[v].size() >= maxD) {
				build(u, v);
				return 0;
			}

			if (g[u].size() < maxD) {
				int common = 0;
				for (int k = 0; k < g[u].size(); ++k) {
					if (g[u][k] != v && binary_search(g[v].begin(), g[v].end(), g[u][k])) {
						++common;
					}
				}

				int nh = h;
				int nt = t;
				nh -= (g[u].size() - 1 - common);
				nt -= (g[v].size() - 1 - common);

				int needed = (nh > 0 ? nh : 0) + (nt > 0 ? nt : 0);
				if (needed <= common) {
					build(u, v);
					return 0;
				}
			} else {
				int common = 0;
				for (int k = 0; k < g[v].size(); ++k) {
					if (g[v][k] != u && binary_search(g[u].begin(), g[u].end(), g[v][k])) {
						++common;
					}
				}

				int nh = h;
				int nt = t;
				nh -= (g[u].size() - 1 - common);
				nt -= (g[v].size() - 1 - common);

				int needed = (nh > 0 ? nh : 0) + (nt > 0 ? nt : 0);
				if (needed <= common) {
					build(u, v);
					return 0;
				}
			}
		}
	}

	printf("NO\n");


	return 0;
}