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
int n;
vector < int > g[maxN];
bool isChain[maxN];
int chains[maxN], nonChains[maxN];
int used[maxN];

void dfs1(int v) {
	used[v] = true;
	vector < int > children;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			children.push_back(g[v][i]);
			dfs1(g[v][i]);
		}
	}

	chains[v] = nonChains[v] = 0;
	for (int i = 0; i < children.size(); ++i) {
		int u = children[i];
		if (isChain[u]) {
			++chains[v];
		} else {
			++nonChains[v];
		}
	}

	if (chains[v] <= 1 && nonChains[v] == 0) {
		isChain[v] = true;
	} else {
		isChain[v] = false;
	}
}

const int inf = 1000000000;

bool build(int v, int have = 2) {
	used[v] = true;
	vector < int > children;
	int cnt = 0, cnt2 = 0;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			int u = g[v][i];
			if (chains[u] <= 2 && nonChains[u] == 0) {
				++cnt;

				if (isChain[u]) {
					++cnt2;
				}
				continue;
			}
			children.push_back(u);
		}
	}

	if (children.size() > have) {
		return false;
	}

	int bound = 1;
	if (children.size() == 1 && cnt2 <= 2 && cnt2 == cnt) {
		bound = min(2, have);
	}

	for (int i = 0; i < children.size(); ++i) {
		if (!build(children[i], bound)) {
			return false;
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int root = 1;
	for (int i = 1; i <= n; ++i) {
		if (g[i].size() > g[root].size()) {
			root = i;
		}
	}
	memset(used, 0, sizeof(used));
	dfs1(root);

	memset(used, 0, sizeof(used));
	if (build(root)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}