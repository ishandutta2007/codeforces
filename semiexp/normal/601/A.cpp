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

int N, M;
vector<int> graph[404];

int wf[404][404];

int calc()
{
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k)
		wf[j][k] = min(wf[j][k], wf[j][i] + wf[i][k]);
	return wf[0][N - 1];
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			wf[i][j] = (i == j ? 0 : 1000);
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j : graph[i]) {
			wf[i][j] = 1;
		}
	}
	int ans = calc();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			wf[i][j] = (i == j ? 0 : 1);
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j : graph[i]) {
			wf[i][j] = 1000;
		}
	}
	ans = max(ans, calc());
	if (ans > N) ans = -1;
	printf("%d\n", ans);

	return 0;
}