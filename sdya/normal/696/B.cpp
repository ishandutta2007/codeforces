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

const int maxN = 110000;
vector < int > g[maxN];
int n, s[maxN];

double p[maxN];

void dfs(int v) {
	s[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		dfs(g[v][i]);
		s[v] += s[g[v][i]];
	}
}

void calc(int v, double res = 0) {
	p[v] = res + 1;
	double t = 1.0 + (double)(s[v] - 1) / 2.0;

	for (int i = 0; i < g[v].size(); ++i) {
		calc(g[v][i], res + t - (double)(s[g[v][i]]) / 2.0);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u;
		scanf("%d", &u);
		g[u - 1].push_back(i);
	}

	dfs(0);
	calc(0);

	for (int i = 0; i < n; ++i) {
		printf("%.10lf ", p[i]);
	}
	printf("\n");

	return 0;
}