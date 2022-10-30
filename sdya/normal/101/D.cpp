#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const long double eps = 1e-15;
int n;
vector < pair < int, int > > g[maxN];
bool used[maxN];

long double d[maxN], c[maxN], s[maxN], p[maxN];

bool comp(int u, int v) {
	long double t = c[u] + c[v];
	long double A = c[u] / t * (d[u] + p[u] / 2.0) + (t - c[u]) / t * (s[u] + p[u] + d[v] + p[v] / 2.0);
	long double B = c[v] / t * (d[v] + p[v] / 2.0) + (t - c[v]) / t * (s[v] + p[v] + d[u] + p[u] / 2.0);
	return A < B - eps;
}

void dfs(int v) {
	used[v] = true;
	vector < int > children;
	c[v] = 1.0;
	s[v] = 0.0;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i].first]) {
			p[g[v][i].first] = 2 * g[v][i].second;
			dfs(g[v][i].first);
			c[v] += c[g[v][i].first];
			s[v] += (long double)(g[v][i].second) * 2.0 + s[g[v][i].first];
			children.push_back(g[v][i].first);
		}
	}

	sort(children.begin(), children.end(), comp);

	d[v] = 0.0;
	long double t = c[v] - 1.0;
	long double coef = 1.0;
	if (v != 1) {
		coef = t / c[v];
	}
	for (int i = 0; i < children.size(); ++i) {
		int u = children[i];
		d[v] += coef * (c[u] / t * (d[u] + p[u] / 2.0) + (t - c[u]) / t * (s[u] + p[u]));
		coef *= (t - c[u]) / t;
		t -= c[u];
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}

	dfs(1);
	printf("%.10lf\n", (double)(d[1]));
	
	return 0;
}