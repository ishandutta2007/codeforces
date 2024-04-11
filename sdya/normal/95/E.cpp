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

const int maxN = 100010;
int n, m;
vector < int > g[maxN];
bool used[maxN];
bool isOk[maxN];

void dfs(int v, int &cnt) {
	used[v] = true;
	++cnt;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i], cnt);
		}
	}
}

bool isLucky(int n) {
	while (n) {
		if (n % 10 != 4 && n % 10 != 7) {
			return false;
		}
		n /= 10;
	}
	return true;
}

int d[2][maxN];

void setUp(int d[]) {
	for (int i = 0; i <= n; ++i) {
		d[i] = n + 1;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	map < int, int > M;
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			int cnt = 0;
			dfs(i, cnt);
			++M[cnt];
		}
	}

	for (int i = 1; i < maxN; ++i) {
		isOk[i] = isLucky(i);
	}

	vector < pair < int, int > > a;
	for (map < int, int > ::iterator it = M.begin(); it != M.end(); ++it) {
		a.push_back(*it);
	}

	if (n >= 77777) {
		n = 77777;
	}

	int u = 0, v = 1;
	setUp(d[u]);
	d[u][0] = 0;
	int res = n + 1;
	for (int step = 0; step < a.size(); ++step, swap(u, v)) {
		setUp(d[v]);
		int x = a[step].first;
		int cnt = a[step].second;
		for (int i = 0; i <= n; ++i) {
			if (d[u][i] > n) {
				continue;
			}
			int left = min(cnt, res - d[u][i]);
			for (int j = i, k = 0; j <= n && k <= left; j += x, ++k) {
				d[v][j] = min(d[v][j], d[u][i] + k);
			}
		}
		for (int i = 0; i <= n; ++i) {
			if (isOk[i]) {
				res = min(res, d[v][i]);
			}
		}
	}

	if (res > n) {
		res = 0;
	}

	printf("%d\n", res - 1);
	
	return 0;
}