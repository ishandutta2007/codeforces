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

const int maxN = 1100;
int n, m, k;
vector < int > g[maxN];
int c[maxN];

bool used[maxN];
bool cap[maxN];

void dfs(int v, vector < int > &c) {
	used[v] = true;
	c.push_back(v);
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i], c);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &c[i]);
		--c[i];
		cap[c[i]] = true;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector < vector < int > > comps;
	int res = 0;

	vector < int > a, b;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			vector < int > t;
			dfs(i, t);
			int edges = 0;
			for (int j = 0; j < t.size(); ++j) {
				edges += g[t[j]].size();
			}
			edges /= 2;

			res += ((t.size() - 1) * t.size()) / 2 - edges;

			bool isgood = false;
			for (int j = 0; j < t.size(); ++j) {
				if (cap[t[j]]) {
					isgood = true;
				}
			}
			if (isgood) {
				a.push_back(t.size());
			} else {
				b.push_back(t.size());
			}
		}
	}

	sort(a.rbegin(), a.rend());

	int x = a[0];
	for (int i = 0; i < b.size(); ++i) {
		res += x * b[i];
		x += b[i];
	}

	cout << res << endl;


	return 0;
}