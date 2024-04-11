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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

void getRange(int& mode, int& l, int& r, int x, int y, int n) {
	l = x - y;
	r = x + y;

	if (l < 0) {
		l = -l;
	}
	if (r >= n) {
		r = 2 * n - 2 - r;
	}

	if (l % 2 == 0) {
		mode = 0;
		l /= 2;
		r /= 2;
	} else {
		mode = 1;
		l /= 2;
		r /= 2;
	}
	++l;
	++r;
}

const int maxN = 110000;
const long long P = 1000000007LL;
vector < pair < int, int > > g[2][maxN];
bool used[maxN];
int c[maxN];

void dfs(int mode, int v, int color = 0) {
	if (used[v]) {
		return ;
	}

	used[v] = true;
	c[v] = color;

	for (int i = 0; i < g[mode][v].size(); ++i) {
		int u = g[mode][v][i].first;
		int value = g[mode][v][i].second;

		if (used[u] && c[u] != (c[v] + value) % 2) {
			printf("0\n");
			exit(0);
		}
		if (!used[u]) {
			dfs(mode, u, (color + value) % 2);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i) {
		int x, y;
		char s;
		scanf("%d %d %c", &x, &y, &s);

		int mode, l, r;
		getRange(mode, l, r, x - 1, y - 1, n);
		int value = (s == 'x' ? 0 : 1);

		g[mode][l - 1].push_back(make_pair(r, value));
		g[mode][r].push_back(make_pair(l - 1, value));
	}

	long long res = 1;
	int b[2] = {0, 0};
	for (int i = 0; i < n; ++i) {
		b[i % 2] = max(b[i % 2], (i / 2) + 1);
	}
	for (int i = 0; i < 2; ++i) {
		memset(used, 0, sizeof(used));
		for (int j = 0; j <= b[i]; ++j) {
			if (!used[j]) {
				dfs(i, j, 0);
				if (j != 0) {
					res += res;
					res %= P;
				}
			}
		}
	}

	cout << res << endl;

	return 0;
}