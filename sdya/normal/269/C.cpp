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

const int maxN = 210000;
int res[maxN];
int deg[maxN];

int u[maxN], v[maxN], w[maxN];
vector < int > g[maxN];
bool used[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);

	set < pair < int, int > > S;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		deg[u[i]] += w[i];
		deg[v[i]] += w[i];
		g[u[i]].push_back(i);
		g[v[i]].push_back(i);
	}

	for (int i = 2; i < n; ++i) {
		deg[i] /= 2;
	}
	deg[1] = 0;

	for (int i = 1; i <= n; ++i) {
		S.insert(make_pair(deg[i], i));
	}

	while (!S.empty()) {
		int v = S.begin()->second;
		S.erase(S.begin());
		for (int i = 0; i < g[v].size(); ++i) {
			int index = g[v][i];
			if (used[index]) {
				continue;
			}

			used[index] = true;
			int u = (::u[index] != v ? ::u[index] : ::v[index]);
			if (::u[index] != v) {
				res[index] = 1;
			}

			S.erase(make_pair(deg[u], u));
			deg[u] -= w[index];
			S.insert(make_pair(deg[u], u));
		}
	}

	for (int i = 0; i < m; ++i) {
		printf("%d\n", res[i]);
	}

	return 0;
}