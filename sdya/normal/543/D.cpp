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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
const long long P = 1000000007LL;
vector < int > g[maxN];
vector < long long > d1[maxN], d2[maxN];

long long d[maxN];
int n;

void dfs1(int v, int parent = -1) {
	d[v] = 1LL;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != parent) {
			dfs1(g[v][i], v);
			d[v] *= (1LL + d[g[v][i]]);
			d[v] %= P;
		}
	}
}

void dfs2(int v, int parent = -1, long long value = 1) {
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] == parent) {
			d1[v][i] = (1LL + value) % P;
			d2[v][i] = (1LL + value) % P;
		} else {
			d1[v][i] = (1LL + d[g[v][i]]) % P;
			d2[v][i] = (1LL + d[g[v][i]]) % P;
		}
	}
	for (int i = 1; i < g[v].size(); ++i) {
		d1[v][i] *= d1[v][i - 1];
		d1[v][i] %= P;
	}
	for (int i = (int)(g[v].size()) - 2; i >= 0; --i) {
		d2[v][i] *= d2[v][i + 1];
		d2[v][i] %= P;
	}

	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] == parent) {
			continue;
		}

		long long buffer = (i == 0 ? 1LL : d1[v][i - 1]) * (i + 1 == g[v].size() ? 1LL : d2[v][i + 1]);
		buffer %= P;
		dfs2(g[v][i], v, buffer);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int u = 2; u <= n; ++u) {
		int v;
		scanf("%d", &v);
		g[u].push_back(v);
		g[v].push_back(u);
		d1[u].push_back(0);
		d2[u].push_back(0);
		d1[v].push_back(0);
		d2[v].push_back(0);
	}

	dfs1(1);
	dfs2(1);

	for (int i = 1; i <= n; ++i) {
		long long res = (g[i].size() == 0 ? 1LL : d1[i][g[i].size() - 1]);
		printf("%d ", (int)(res % P));
	}
	printf("\n");

	return 0;
}