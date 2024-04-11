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

vector < int > buildPath(int u, int v, vector < vector < int > > &g) {
	int n = g.size() - 1;

	vector < int > d(n + 1, -1), p(n + 1, -1);

	queue < int > q;
	q.push(u);

	d[u] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < g[v].size(); ++i) {
			if (d[g[v][i]] == -1) {
				d[g[v][i]] = d[v] + 1;
				p[g[v][i]] = v;
				q.push(g[v][i]);
			}
		}
	}

	vector < int > res;
	int x = v;
	while (x != -1) {
		res.push_back(x);
		x = p[x];
	}
	reverse(res.begin(), res.end());
	return res;
}

void add(vector < int > &g, int v) {
	for (int i = 0; i < g.size(); ++i) {
		if (g[i] == v) {
			return ;
		}
	}
	g.push_back(v);
}

void update(vector < int > &g) {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int u;
		scanf("%d", &u);
		add(g, u);
	}
}

void update(int v, vector < vector < int > > &g) {
	vector < int > t = g[v];
	update(t);
	g[v] = t;
}

int getUnused(int u, vector < vector < int > > &g, vector < bool > &visited) {
	for (int i = 0; i < g[u].size(); ++i) {
		if (!visited[g[u][i]]) {
			return g[u][i];
		}
	}
	return -1;
}

void ask(int u, vector < vector < int > > &g, vector < bool > &visited) {
	visited[u] = true;
	printf("? %d\n", u);
	fflush(stdout);
	update(u, g);
}

int goToLeaf(int u, vector < vector < int > > &g, vector < bool > &visited) {
	while (true) {
		ask(u, g, visited);
		int x = getUnused(u, g, visited);
		if (x == -1) {
			return u;
		}
		u = x;
	}
}

bool check(vector < vector < int > > &g) {
	for (int i = 1; i < g.size(); ++i) {
		if (g[i].size() == 2) {
			printf("! %d\n", i);
			fflush(stdout);
			return true;
		}
	}
	return false;
}

void solve(int u, int v, vector < vector < int > > &g, vector < bool > &visited) {
	if (check(g)) {
		return;
	}
	vector < int > p = buildPath(u, v, g);
	if (p.size() < 7) {
		int r = getUnused(p[p.size() / 2], g, visited);
		int w = goToLeaf(r, g, visited);
		solve(u, w, g, visited);
	} else {
		int r = getUnused(p[p.size() / 2], g, visited);
		ask(r, g, visited);

		if (check(g)) {
			return;
		}

		int x = getUnused(r, g, visited);
		ask(x, g, visited);
		int y = getUnused(r, g, visited);
		ask(y, g, visited);

		if (check(g)) {
			return;
		}

		int x1 = getUnused(x, g, visited);
		ask(x1, g, visited);
		int x2 = getUnused(x, g, visited);
		ask(x2, g, visited);

		int y1 = getUnused(y, g, visited);
		ask(y1, g, visited);

		if (check(g)) {
			return;
		}

		int y2 = getUnused(y, g, visited);
		printf("! %d\n", y2);
		fflush(stdout);
	}
}

void solve() {
	int h;
	scanf("%d", &h);

	int n = (1 << h) - 1;

	vector < vector < int > > g(n + 1);

	vector < bool > visited(n + 1, false);

	ask(1, g, visited);

	int u = (g[1].size() == 1 ? 1 : goToLeaf(g[1][0], g, visited));
	int v = (g[1].size() == 1 ? goToLeaf(g[1][0], g, visited) : goToLeaf(g[1][1], g, visited));

	solve(u, v, g, visited);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		solve();
	}


	return 0;
}