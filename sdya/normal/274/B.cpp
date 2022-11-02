#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long inf = 1000000000000000000LL;
const int maxN = 110000;
int n;
vector < int > g[maxN];
bool used[maxN];
int a[maxN];
long long d[maxN];
long long x[maxN], y[maxN];

void dfs(int v, long long res, int parent = 0) {
	used[v] = true;

	long long value = a[v];
	if (value >= 0) {
		y[v] = value;
	} else {
		x[v] = -value;
	}

	if (v > 1 && (x[v] > x[parent] || y[v] > y[parent])) {
		x[1] = res + 1;
		y[1] = res + 1;
		return ;
	}

	if (v == 1 && res > (x[v] + y[v])) {
		long long add = (res - x[v] - y[v]) / 2;
		x[v] += add;
		y[v] += add;
	}
	if (v != 1 && res > (x[v] + y[v])) {
		long long add = (res - x[v] - y[v]) / 2;
		add = min(x[parent] - x[v], add);
		add = min(y[parent] - y[v], add);
		x[v] += add;
		y[v] += add;
	}

	if (v > 1 && (x[v] > x[parent] || y[v] > y[parent])) {
		x[1] = res + 1;
		y[1] = res + 1;
		return ;
	}

	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i], res, v);
		}
	}
}

bool check(long long res) {
	memset(used, 0, sizeof(used));
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	x[0] = res / 2;
	y[0] = res / 2;
	dfs(1, res);

	for (int i = 1; i <= n; ++i) {
		if (x[i] + y[i] > res) {
			return false;
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	long long left_bound = 0, right_bound = inf;
	while (right_bound - left_bound > 1) {
		long long middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}

	long long res = right_bound;
	if (check(left_bound)) {
		res = left_bound;
	}

	cout << res << endl;

	return 0;
}