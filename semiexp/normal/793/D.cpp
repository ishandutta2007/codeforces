#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

const int INFV = 100100100;

int N, K, M;
vector<pair<int, int>> graph[85];
int dist[85][85];
int dp[85][85][85];

int solve(int s, int t, int d)
{
	if (d == 0) return 0;
	if (dp[s + 1][t + 1][d] != -1) return dp[s + 1][t + 1][d];
	int ans = INFV;
	if (s < t) {
		for (int i = s + 1; i < t; ++i) if (dist[t][i] != INFV) {
			ans = min(ans, solve(t, i, d - 1) + dist[t][i]);
			ans = min(ans, solve(s, i, d - 1) + dist[t][i]);
		}
	} else {
		for (int i = t + 1; i < s; ++i) if (dist[t][i] != INFV) {
			ans = min(ans, solve(t, i, d - 1) + dist[t][i]);
			ans = min(ans, solve(s, i, d - 1) + dist[t][i]);
		}
	}
	//printf("%d %d %d: %d\n", s, t, d, ans);
	return dp[s + 1][t + 1][d] = ans;
}

int main()
{
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 0; i < N + 3; ++i) {
		for (int j = 0; j < N + 3; ++j) {
			dist[i][j] = INFV;
		}
	}
	for (int i = 0; i < M; ++i) {
		int x, y, d;
		scanf("%d%d%d", &x, &y, &d);
		--x; --y;
		if (x == y) continue;
		graph[x].push_back({y, d});
		dist[x][y] = min(dist[x][y], d);
	}
	--K;
	for (int i = 0; i < N + 3; ++i) {
		for (int j = 0; j < N + 3; ++j) {
			for (int k = 0; k <= K; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}
	int ret = INFV;
	if (K == 0) ret = 0;
	for (int i = 0; i < N; ++i) {
		ret = min(ret, solve(-1, i, K));
		ret = min(ret, solve(N, i, K));
	}

	if (ret > INFV / 2) ret = -1;
	printf("%d\n", ret);
	return 0;
}