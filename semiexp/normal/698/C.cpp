#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, K;
double P[25];

double dp[1 << 20];
double ans[1 << 20];

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) scanf("%lf", P + i);

	int nzero = 0;
	for (int i = 0; i < N; ++i) if (P[i] > 1e-4) ++nzero;

	if (nzero <= K) {
		for (int i = 0; i < N; ++i) if (P[i] > 1e-4) ans[i] = 1.0; else ans[i] = 0.0;
	} else {
		dp[0] = 1;
		for (int i = 0; i < (1 << N); ++i) {
			int cnt = __builtin_popcount(i);
			if (cnt == K) {
				for (int j = 0; j < N; ++j) if (i & (1 << j)) ans[j] += dp[i];
				continue;
			}
			if (cnt > K) continue;

			double tot = 0;
			for (int j = 0; j < N; ++j) if (!(i & (1 << j)))  tot += P[j];

			for (int j = 0; j < N; ++j) if (!(i & (1 << j))) {
				dp[i | (1 << j)] += dp[i] * (P[j] / tot);
			}
		}
	}
	for (int i = 0; i < N; ++i) printf("%.10f%c", ans[i], (i == N - 1) ? '\n' : ' ');
	return 0;
}