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

int N, K, A[101010];
i64 cnt[101010]; // # of seqs with beauty >= i

int dp[1010][1010];
int nxt[1010];

i64 solve(int m)
{
	int p = 0;
	for (int i = 0; i < N; ++i) {
		while (p < N && A[p] - A[i] < m) ++p;
		if (p == i) ++p;
		nxt[i] = p;
	}
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < N; ++j) dp[i][j] = 0;
	}
	for (int j = 0; j < K; ++j) {
		if (j == 0) {
			for (int i = 0; i < N; ++i) dp[j][i] = 1;
		} else {
			for (int i = 1; i < N; ++i) ADD(dp[j][i], dp[j][i - 1]);
		}
		if (j == K - 1) break;
		for (int i = 0; i < N; ++i) {
			if (nxt[i] == N) break;
			ADD(dp[j + 1][nxt[i]], dp[j][i]);
		}
	}
	i64 ans = 0;
	for (int i = 0; i < N; ++i) ADD(ans, dp[K - 1][i]);
	return ans;
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	sort(A, A + N);

	for (int i = 0; i <= (A[N - 1] - A[0]) / (K - 1); ++i) {
		cnt[i] = solve(i);
		//printf("%d: %lld\n", i, cnt[i]);
	}
	i64 ret = 0;
	for (int i = 0; i <= (A[N - 1] - A[0]) / (K - 1); ++i) {
		i64 a = (cnt[i] + MOD - cnt[i + 1]) % MOD;
		ADD(ret, a * i);
	}
	printf("%lld\n", ret);
	return 0;
}