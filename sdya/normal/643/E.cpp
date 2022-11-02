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

const int maxN = 510000;
const int maxK = 36;
const double eps = 1e-20;

vector < int > g[maxN];
int q;
int n = 1;
int parent[maxN];

double p[maxN][maxK];
double p2[maxN];

void initVertex(int v) {
	for (int i = 0; i < maxK; ++i) {
		p[v][i] = 1.0;
	}
}

void updateVertex(int v, int u, bool add) {
	for (int i = 1; i < maxK; ++i) {
		double value = 0.5 * (1.0 + p[u][i - 1]);
		if (add) {
			p[v][i] *= value;
		} else {
			p[v][i] /= value;
		}
		if (p[v][i] < eps) {
			p[v][i] = 0.0;
		}
	}

	if (add) {
		p[v][0] = p2[g[v].size()];
	}
}

void addVertex(int v) {
	++n;
	int u = n;

	parent[u] = v;
	g[v].push_back(u);

	int depth = 0;
	vector < int > path;
	path.push_back(u);
	while (v != 0 && depth < maxK) {
		++depth;
		path.push_back(v);
		v = parent[v];
	}

	reverse(path.begin(), path.end());

	for (int i = 0; i + 2 < path.size(); ++i) {
		updateVertex(path[i], path[i + 1], false);
	}

	initVertex(u);
	for (int i = (int)(path.size()) - 2; i >= 0; --i) {
		updateVertex(path[i], path[i + 1], true);
	}
}

double getRes(int v) {
	double res = 0.0;
	for (int i = 1; i < maxK; ++i) {
		double q = p[v][i] - p[v][i - 1];
		res += q * (double)(i);
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	p2[0] = 1.0;
	for (int i = 1; i < maxN; ++i) {
		p2[i] = p2[i - 1] * 0.5;
		if (p2[i] < eps) {
			p2[i] = 0.0;
		}
	}

	scanf("%d", &q);
	initVertex(1);
	for (int i = 0; i < q; ++i) {
		int mode, v;
		scanf("%d%d", &mode, &v);
		if (mode == 1) {
			addVertex(v);
		} else {
			printf("%.10lf\n", getRes(v));
		}
	}

	return 0;
}