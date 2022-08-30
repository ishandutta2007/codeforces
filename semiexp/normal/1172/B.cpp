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
#define MOD 998244353
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N;
vector<int> graph[202020];
i64 fact[202020];

i64 solve(int p, int rt = -1)
{
	vector<i64> ch;
	for (int q : graph[p]) {
		if (q == rt) continue;
		ch.push_back(solve(q, p));
	}
	i64 ret = 1;
	for (i64 v : ch) ret = ret * v % MOD;
	if (rt == -1) {
		ret = ret * N % MOD * fact[ch.size()] % MOD;
	} else {
		ret = ret * fact[ch.size() + 1] % MOD;
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	fact[0] = 1;
	for (int i = 1; i <= N; ++i) fact[i] = fact[i - 1] * i % MOD;

	i64 ans = solve(0);
	printf("%lld\n", ans);

	return 0;
}