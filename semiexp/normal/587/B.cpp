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
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

i64 modpow(i64 v, int p = MOD - 2)
{
	if (p == 0) return 1;
	i64 ret = modpow(v, p / 2);
	ret = ret * ret % MOD;
	if (p % 2 == 1) ret = ret * v % MOD;
	return ret;
}

int N, K;
i64 L;
int A[1010101];
i64 dp[1010101];

i64 preb[1010101];
i64 tot[1010101];

i64 C(i64 A, int B)
{
	if (A < B) return 0;
	return (A - B + 1) % MOD;
	i64 ret = 1;
	for (int i = 0; i < B; ++i) {
		ret = ret * ((A - i) % MOD) % MOD;
		ret = ret * modpow(i + 1) % MOD;
	}
	return ret;
}

int main()
{
	scanf("%d%lld%d", &N, &L, &K);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	vector<int> As;
	for (int i = 0; i < N; ++i) As.push_back(A[i]);
	sort(As.begin(), As.end());
	As.erase(unique(As.begin(), As.end()), As.end());
	for (int i = 0; i < N; ++i) A[i] = lower_bound(As.begin(), As.end(), A[i]) - As.begin();

	int S = As.size();
	for (int i = 0; i < N; ++i) dp[i] = 1;

	for (int i = 1; i < K; ++i) {
		for (int j = 0; j < S; ++j) preb[j] = 0;
		for (int j = 0; j < N; ++j) ADD(preb[A[j]], dp[j + (i - 1) * N]);
		for (int j = 1; j < S; ++j) ADD(preb[j], preb[j - 1]);
		for (int j = 0; j < N; ++j) dp[j + i * N] = preb[A[j]];
	}
	for (int i = 1; i <= K; ++i) tot[i] = 0;
	for (int j = 0; j < N * K; ++j) ADD(tot[j / N + 1], dp[j]);

	i64 ret = 0;
	i64 usable = L / N;
	for (int i = 1; i <= K; ++i) if (i <= usable) {
	//	printf("%d: %lld\n", i, C(usable, i) * tot[i]);
		ADD(ret, C(usable, i) * tot[i] % MOD);
	}
	int rem = (int)(L % (i64)N);
	for (int i = 0; i < rem; ++i) {
		for (int j = 1; j <= K; ++j) if (j - 1 <= usable) {
		//	printf("%d %d: %lld\n", i, j, dp[(j - 1) * N + i]);
			ADD(ret, 1 * dp[(j - 1) * N + i] % MOD);
		}
	}

	printf("%lld\n", ret);
	return 0;
}