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

const int maxN = 210000;
const long long inf = 1000000000000000000LL;
int n, p[maxN], a[maxN];
vector < int > g[maxN];
long long d[2][maxN];
long long dp[2][2];

void dfs(int v) {
	for (int i = 0; i < g[v].size(); ++i) {
		dfs(g[v][i]);
	}

	d[0][v] = d[1][v] = -inf;
	
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			dp[i][j] = -inf;
		}
	}
	int x = 0, y = 1;
	dp[x][0] = 0;
	for (int i = 0; i < g[v].size(); ++i, swap(x, y)) {
		dp[y][0] = dp[y][1] = -inf;
		for (int j = 0; j < 2; ++j) {
			if (dp[x][j] == -inf) {
				continue;
			}
			dp[y][j] = max(dp[y][j], dp[x][j] + d[0][g[v][i]]);
			dp[y][(j + 1) % 2] = max(dp[y][(j + 1) % 2], dp[x][j] + d[1][g[v][i]]);
		}
	}
	d[0][v] = dp[x][0];
	d[1][v] = dp[x][1];

	d[1][v] = max(d[1][v], (long long)(a[v]) + dp[x][0]);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &p[i], &a[i]);
		if (p[i] != -1) {
			g[p[i]].push_back(i);
		}
	}

	dfs(1);
	long long res = max(d[0][1], d[1][1]);
	cout << res << endl;

	return 0;
}