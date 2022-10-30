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
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, m, k;
vector < int > g[maxN];
bool used[maxN];
bool taken[maxN];

struct Rational {
	long long x;
	long long y;

	Rational() : x(0), y(1) {}
	Rational(long long x, long long y) : x(x), y(y) {}
	bool operator < (const Rational &other) const {
		return x * other.y < y * other.x;
	}
	bool isLess(double q) {
		return (double)(x) / (double)(y) < q - 1e-8;
	}
	bool operator <= (const Rational &other) const {
		return x * other.y <= y * other.x;
	}
};

Rational d[maxN];

bool marked[maxN];

bool check(double q) {
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			taken[i] = true;
		} else {
			taken[i] = false;
		}
		marked[i] = false;
	}

	vector < int > candidates;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}

		int x = 0;
		for (int j = 0; j < g[i].size(); ++j) {
			if (!used[g[i][j]]) {
				++x;
			}
		}
		d[i] = Rational(x, g[i].size());
		if (d[i].isLess(q)) {
			candidates.push_back(i);
			marked[i] = true;
		}
	}

	while (!candidates.empty()) {
		int v = candidates.back();
		candidates.pop_back();
		taken[v] = true;

		for (int i = 0; i < g[v].size(); ++i) {
			int u = g[v][i];
			if (taken[u]) {
				continue;
			}
			d[u].x -= 1;
			if (!marked[u] && d[u].isLess(q)) {
				candidates.push_back(u);
				marked[u] = true;
			}
		}
	}

	int cnt = count(taken, taken + n, false);
	return cnt > 0;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; ++i) {
		int v;
		scanf("%d", &v);
		--v;
		used[v] = true;
	}

	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	

	double l = 0.0, r = 1.0;
	for (int i = 0; i < 50; ++i) {
		double m = (l + r) / 2;
		if (check(m)) {
			l = m;
		} else {
			r = m;
		}
	}

	check(l);

	printf("%d\n", count(taken, taken + n, false));
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			printf("%d ", i + 1);
		}
	}
	printf("\n");

	return 0;
}