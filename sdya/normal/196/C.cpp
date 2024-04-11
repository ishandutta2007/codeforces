#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2000;

struct point {
	int x, y;
	int number;
	double ang;
	point() {
	}
	point(int x, int y, int number, double ang) : x(x), y(y), number(number), ang(ang) {
	}
	bool operator < (const point &other) const {
		return ang < other.ang;
	}
};
vector < int > h[maxN];
vector < int > g[maxN];
int used[maxN], cap[maxN];
int n;
vector < point > p;

void dfs(int v) {
	if (used[v]) {
		return ;
	}
	used[v] = true;
	cap[v] = 1;

	for (int i = 0; i < h[v].size(); ++i) {
		if (!used[h[v][i]]) {
			g[v].push_back(h[v][i]);
			dfs(h[v][i]);
			cap[v] += cap[h[v][i]];
		}
	}
}

int res[maxN];

void solve(const vector < point > &p, int v) {
	point best = p[0];
	for (int i = 0; i < p.size(); ++i) {
		if (p[i].y > best.y) {
			best = p[i];
		} else if (p[i].y == best.y && p[i].x < best.x) {
			best = p[i];
		}
	}

	//cerr << best.x << " " << best.y << " " << best.number << endl;
	res[best.number] = v;
	vector < point > q;
	int m = 0;
	for (int i = 0; i < p.size(); ++i) {
		if (p[i].x != best.x || p[i].y != best.y) {
			q.push_back(point(p[i].x, p[i].y, p[i].number, 0.0));
			q[m ++].ang = atan2((double)(p[i].y - best.y), (double)(p[i].x - best.x));
		}
	}

	sort(q.begin(), q.end());
	int cur = 0;
	for (int i = 0; i < g[v].size(); ++i) {
		int count = cap[g[v][i]];
		vector < point > buf;
		for (int j = cur; j < cur + count; ++j) {
			buf.push_back(q[j]);
		}
		cur += count;
		solve(buf, g[v][i]);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		h[u].push_back(v);
		h[v].push_back(u);
	}

	dfs(1);

	for (int i = 1; i <= n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		p.push_back(point(x, y, i, 0.0));
	}

	solve(p, 1);

	for (int i = 1; i <= n; ++i) {
		printf("%d ", res[i]);
	}
	printf("\n");


	return 0;
}