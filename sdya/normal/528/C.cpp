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
#include <complex>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n;
unordered_map < int, int > g[maxN];

void find_path(int v, vector < int > &path) {
	while (!g[v].empty()) {
		int u = g[v].begin()->first;
		--g[v][u];
		if (g[v][u] == 0) {
			g[v].erase(u);
		}
		--g[u][v];
		if (g[u][v] == 0) {
			g[u].erase(v);
		}
		find_path(u, path);
	}
	path.push_back(v);
}

void addEdge(int u, int v) {
	++g[u][v];
	++g[v][u];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int m;
	scanf("%d%d", &n, &m);
	vector < int > d(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u - 1, v - 1);
		++d[u - 1];
		++d[v - 1];
	}

	vector < int > odd, even;
	for (int i = 0; i < n; ++i) {
		if (d[i] % 2 == 1) {
			odd.push_back(i);
		} else {
			even.push_back(i);
		}
	}

	if ((odd.size() / 2 + m) % 2 != 0) {
		addEdge(0, 0);
	}
	for (int i = 0; i < odd.size(); i += 2) {
		addEdge(odd[i], odd[i + 1]);
	}

	vector < int > p;
	find_path(0, p);

	printf("%d\n", p.size() - 1);
	for (int i = 1; i < p.size(); ++i) {
		if (i % 2 == 1) {
			printf("%d %d\n", p[i - 1] + 1, p[i] + 1);
		} else {
			printf("%d %d\n", p[i] + 1, p[i - 1] + 1);
		}
	}


	return 0;
}