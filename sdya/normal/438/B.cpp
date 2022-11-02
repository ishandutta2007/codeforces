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
int p[maxN], c[maxN];

int find(int v) {
	if (v == p[v]) {
		return v;
	}
	return p[v] = find(p[v]);
}

void merge(int u, int v) {
	int x = find(u);
	int y = find(v);

	if (rand() % 2) {
		c[x] += c[y];
		p[y] = x;
	} else {
		c[y] += c[x];
		p[x] = y;
	}
}

int n, m;
int v[maxN];

vector < int > g[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	vector < pair < int, int > > order;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
		order.push_back(make_pair(v[i], i));
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	sort(order.rbegin(), order.rend());

	double res = 0.0;
	for (int i = 0; i < n; ++i) {
		p[i] = i;
		c[i] = 1;
	}
	vector < bool > used(n);

	for (int i = 0; i < n; ++i) {
		int w = order[i].first;
		int v = order[i].second;
		for (int j = 0; j < g[v].size(); ++j) {
			if (used[g[v][j]]) {
				int c1 = find(g[v][j]);
				int c2 = find(v);
				if (c1 != c2) {
					res += (double)(w) * (double)(c[c1]) * (double)(c[c2]);
					merge(c1, c2);
				}
			}
		}
		used[v] = true;
	}
	res /= n;
	res /= (n - 1);

	printf("%.10lf\n", res * 2.0);

	return 0;
}