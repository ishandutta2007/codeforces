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

const long long P = 1000000007LL;
const int maxN = 110000;
vector < int > g[maxN];
int n;
int c[maxN];

long long d[2][maxN];

long long dp[maxN][2];

void dfs(int v) {
	for (int i = 0; i < g[v].size(); ++i) {
		dfs(g[v][i]);
	}

	if (g[v].size() == 0) {
		d[c[v]][v] = 1;
		return ;
	}

	for (int i = 0; i <= g[v].size(); ++i) {
		dp[i][0] = dp[i][1] = 0;
	}

	dp[0][c[v]] = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		for (int j = 0; j < 2; ++j) {
			if (dp[i][j] == 0) {
				continue;
			}

			// has edge
			{
				for (int k = 0; k < 2; ++k) {
					if (j + k < 2) {
						dp[i + 1][j + k] += dp[i][j] * d[k][g[v][i]];
						dp[i + 1][j + k] %= P;
					}
				}
			}

			// no edge
			{
				dp[i + 1][j] += dp[i][j] * d[1][g[v][i]];
				dp[i + 1][j] %= P;
			}
		}
	}

	d[0][v] = dp[g[v].size()][0];
	d[1][v] = dp[g[v].size()][1];
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int v;
		scanf("%d", &v);
		g[v].push_back(i + 1);
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &c[i]);
		cnt += c[i];
	}
	if (cnt == 0) {
		printf("0\n");
		return 0;
	}

	dfs(0);
	cout << d[1][0] << endl;

	return 0;
}