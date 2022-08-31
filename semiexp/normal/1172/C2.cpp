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

i64 modpow(i64 x, int p = MOD - 2)
{
	if (p == 0) return 1;
	i64 tmp = modpow(x, p / 2);
	tmp = tmp * tmp % MOD;
	if (p % 2 == 1) tmp = tmp * x % MOD;
	return tmp;
}

int N, M;
int A[202020], W[202020];
vector<int> pos, posloc, nega, negaloc;
i64 ans[202020];

i64 sum(vector<int> &v)
{
	i64 ret = 0;
	for (int x : v) ret += x;
	return ret;
}

i64 dp[3030][3030];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	for (int i = 0; i < N; ++i) scanf("%d", W + i);

	for (int i = 0; i < N; ++i) {
		if (A[i] == 0) {
			nega.push_back(W[i]);
			negaloc.push_back(i);
		} else {
			pos.push_back(W[i]);
			posloc.push_back(i);
		}
	}

	i64 negasum = sum(nega), possum = sum(pos);
	dp[0][0] = 1;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < M - i; ++j) {
			if (dp[i][j] == 0) continue;
			i64 ng = negasum - i, ps = possum + j;
			// dp[i + 1][j] += dp[i][j] * ng / (ng + ps)
			ADD(dp[i + 1][j], dp[i][j] * ng % MOD * modpow(ng + ps));

			// dp[i][j + 1] += dp[i][j] * ps / (ng + ps)
			ADD(dp[i][j + 1], dp[i][j] * ps % MOD * modpow(ng + ps));
		}
	}

	i64 pos_expv = 0, nega_expv = 0;
	for (int i = 0; i <= M; ++i) {
		ADD(nega_expv, dp[i][M - i] * i % MOD);
		ADD(pos_expv, dp[i][M - i] * (M - i) % MOD);
	}

	for (int i = 0; i < pos.size(); ++i) {
		ans[posloc[i]] = pos[i] * (1 + pos_expv * modpow(possum) % MOD) % MOD;
	}
	for (int i = 0; i < nega.size(); ++i) {
		ans[negaloc[i]] = nega[i] * (1 + MOD - nega_expv * modpow(negasum) % MOD) % MOD;
	}
	for (int i = 0; i < N; ++i) printf("%lld\n", ans[i]);
	
	return 0;
}