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

const int maxN = 110000;
const int inf = 1000000;
int n, m, d;

vector < int > g[maxN];
int t[4 * maxN], add[4 * maxN];
int l[maxN], r[maxN], used[maxN];
int candidates[maxN];
int value[maxN];
int pos[maxN];

int cnt = 0;

void dfs(int v, int dist = 0) {
	l[v] = cnt++;
	value[l[v]] = dist;
	pos[l[v]] = v;
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i], dist + 1);
		}
	}
	r[v] = cnt - 1;
}

void init(int i, int l, int r) {
	if (l == r) {
		add[i] = 0;
		t[i] = (candidates[pos[l]] ? value[l] : -inf);
		return ;
	}
	init(2 * i, l, (l + r) / 2);
	init(2 * i + 1, (l + r) / 2 + 1, r);
	t[i] = max(t[2 * i], t[2 * i + 1]);
	add[i] = 0;
}

void update(int i, int l, int r, int cl, int cr, int delta) {
	if (l == cl && r == cr) {
		t[i] += delta;
		add[i] += delta;
		return ;
	}
	if (cl > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, delta);
	} else if (cr <= (l + r) / 2) {
		update(2 * i, l, (l + r) / 2, cl, cr, delta);
	} else {
		update(2 * i, l, (l + r) / 2, cl, (l + r) / 2, delta);
		update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, delta);
	}
	t[i] = max(t[2 * i], t[2 * i + 1]) + add[i];
}

void dfs2(int v, int &res) {
	int score = t[1];
	if (score <= d) {
		++res;
	}
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		if (used[g[v][i]]) {
			continue;
		}
		update(1, 0, cnt - 1, 0, cnt - 1, +1);
		update(1, 0, cnt - 1, l[g[v][i]], r[g[v][i]], -2);
		dfs2(g[v][i], res);
		update(1, 0, cnt - 1, l[g[v][i]], r[g[v][i]], +2);
		update(1, 0, cnt - 1, 0, cnt - 1, -1);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < m; ++i) {
		int v;
		scanf("%d", &v);
		candidates[v] = true;
	}

	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		used[i] = false;
	}
	init(1, 0, cnt - 1);
	int res = 0;
	dfs2(1, res);
	printf("%d\n", res);

	return 0;
}