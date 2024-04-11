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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000000007LL;
const int maxN = 210000;
int a[maxN], b[maxN];
int n;

vector < int > g[maxN], gr[maxN];

bool used[maxN];

void dfs(int v, vector < int > &comp) {
	used[v] = true;
	comp.push_back(v);
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i], comp);
		}
	}
	for (int i = 0; i < gr[v].size(); ++i) {
		if (!used[gr[v][i]]) {
			dfs(gr[v][i], comp);
		}
	}
}

long long calc(int v) {
	long long res = 1;
	for (int i = 0; i < gr[v].size(); ++i) {
		res = (res + calc(gr[v][i])) % P;
	}
	return res;
}

long long solve(int v) {
	vector < int > c;
	dfs(v, c);

	int edges = 0;
	for (int i = 0; i < c.size(); ++i) {
		edges += g[c[i]].size();
	}
	if (edges == c.size()) {
		bool identity = false;
		for (int i = 0; i < c.size(); ++i) {
			if (c[i] == g[c[i]][0]) {
				identity = true;
			}
		}
		return (identity ? 1 : 2);
	}

	int root = v;
	while (g[root].size() != 0) {
		root = g[root][0];
	}

	return calc(root);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		g[a[i]].push_back(b[i]);
		gr[b[i]].push_back(a[i]);
		mx = max(mx, a[i]);
		mx = max(mx, b[i]);
	}

	long long res = 1;
	for (int i = 0; i <= mx; ++i) {
		if (used[i]) {
			continue;
		}
		res = res * solve(i);
		res %= P;
	}
	cout << res << endl;

	return 0;
}