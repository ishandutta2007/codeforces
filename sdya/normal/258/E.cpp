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
vector < int > g[maxN];
int n, m;
int a[maxN], b[maxN];
int cnt[maxN];

vector < int > marked[maxN];
bool used[maxN];

int pos[maxN], L[maxN], R[maxN], id = 0;

void dfs(int v) {
	used[v] = true;
	++id;
	pos[v] = id;
	L[v] = id;
	for (int i = 0; i < g[v].size(); ++i) {
		if (used[g[v][i]]) {
			continue;
		}
		dfs(g[v][i]);
	}
	R[v] = id;
}

int res[maxN];

pair < int, int > t[4 * maxN];
int add[4 * maxN];

void init(int i, int l, int r) {
	if (l == r) {
		t[i] = make_pair(0, r - l + 1);
		return ;
	}
	init(2 * i, l, (l + r) / 2);
	init(2 * i + 1, (l + r) / 2 + 1, r);
	t[i].first = 0;
	t[i].second = r - l + 1;
}

void update(int i, int l, int r, int cl, int cr, int delta) {
	if (l == cl && r == cr) {
		t[i].first += delta;
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

	t[i].first = min(t[2 * i].first, t[2 * i + 1].first);

	t[i].second = 0;
	if (t[2 * i].first == t[i].first) {
		t[i].second += t[2 * i].second;
	}
	if (t[2 * i + 1].first == t[i].first) {
		t[i].second += t[2 * i + 1].second;
	}

	t[i].first += add[i];
}

int get() {
	if (t[1].first == 0) {
		return t[1].second;
	} else {
		return 0;
	}
}

void calc(int v) {
	used[v] = true;
	for (int i = 0; i < marked[v].size(); ++i) {
		int u = marked[v][i];
		update(1, 1, n, L[u], R[u], +1);
	}

	res[v] = max(0, n - get() - 1);

	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			calc(g[v][i]);
		}
	}

	for (int i = 0; i < marked[v].size(); ++i) {
		int u = marked[v][i];
		update(1, 1, n, L[u], R[u], -1);
	}
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		marked[a[i]].push_back(a[i]);
		marked[a[i]].push_back(b[i]);
		marked[b[i]].push_back(a[i]);
		marked[b[i]].push_back(b[i]);
	}

	dfs(1);
	memset(used, 0, sizeof(used));
	int score = 0;
	init(1, 1, n);
	calc(1);

	for (int i = 1; i <= n; ++i) {
		printf("%d ", res[i]);
	}
	printf("\n");


	return 0;
}