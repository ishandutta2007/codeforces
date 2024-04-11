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

int TC;
int N;
vector<int> graph[101010];
i64 L[101010], R[101010], V[101010][2];
i64 dp[101010][2];

i64 dist(i64 x, i64 y) {
	return x > y ? (x - y) : (y - x);
}

void solve(int p, int rt = -1) {
	i64 best[2] = {0, 0};

	for (int q : graph[p]) {
		if (q == rt) continue;

		solve(q, p);
		for (int i = 0; i < 2; ++i) {
			i64 c = max(dist(V[p][i], V[q][0]) + dp[q][0], dist(V[p][i], V[q][1]) + dp[q][1]);
			best[i] += c;
		}
	}
	
	dp[p][0] = best[0];
	dp[p][1] = best[1];
}

int main()
{
	scanf("%d", &TC);
	for (;TC--;) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			int l, r;
			scanf("%d%d", &l, &r);
			L[i] = l;
			R[i] = r;
			graph[i].clear();

			V[i][0] = l;
			V[i][1] = r;
		}
		for (int i = 0; i < N - 1; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x; --y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		solve(0);
		printf("%lld\n", max(dp[0][0], dp[0][1]));
	}

	return 0;
}