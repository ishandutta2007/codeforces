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

const int maxB = 23000;
const int maxN = 155;
const int inf = 1000000000;
int dp[2][maxN][maxB];
int n, k, s, a[maxN];

void setInf(int dp[maxN][maxB]) {
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j < maxB; ++j) {
			dp[i][j] = inf;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &k, &s);
	s += s;
	if (s > maxB - 1) {
		s = maxB - 1;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	int t = 0;
	for (int i = k; i < n; ++i) {
		t += i;
	}
	int u = 0, v = 1;
	setInf(dp[u]);
	dp[u][0][t] = 0;
	for (int i = 0; i < n; ++i, swap(u, v)) {
		setInf(dp[v]);
		for (int x = 0; x <= k && x <= i; ++x) {
			int z = n - 1 - (i - x);
			for (int y = 0; y < maxB; ++y) {
				if (dp[u][x][y] == inf) {
					continue;
				}

				if (x < k) {
					dp[v][x + 1][y + i - x] = min(dp[v][x + 1][y + i - x], dp[u][x][y] + a[i]);
				}
				if (z >= k) {
					dp[v][x][y - i] = min(dp[v][x][y - i], dp[u][x][y]);
				}
			}
		}
	}

	int res = inf;
	for (int i = 0; i <= s; ++i) {
		res = min(res, dp[u][k][i]);
	}
	printf("%d\n", res);

	//cerr << clock() << endl;

	return 0;
}