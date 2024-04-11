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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, k, p;
vector < int > g[maxN];

bool used[maxN];
vector < int > d;

long long s[maxN];

void dfs(int v, int depth = 0) {
	used[v] = true;
	if (depth > 0) {
		d.push_back(depth);
	}
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i], depth + 1);
		}
	}
}

bool check(int cnt) {
	for (int i = cnt - 1; i < d.size(); ++i) {
		long long total = s[i] - ((i - cnt) < 0 ? 0 : s[i - cnt]);
		long long needed = (long long)(cnt) * (long long)(d[i]) - total;
		if (needed <= (long long)(p)) {
			return true;
		}
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	sort(d.begin(), d.end());

	s[0] = d[0];
	for (int i = 1; i < d.size(); ++i) {
		s[i] = d[i];
		s[i] += s[i - 1];
	}

	int l = 0, r = min(n - 1, k);
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (check(m)) {
			l = m;
		} else {
			r = m;
		}
	}

	int res = l;
	if (check(r)) {
		res = r;
	}

	printf("%d\n", res);

	return 0;
}