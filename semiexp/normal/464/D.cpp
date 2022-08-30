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

double dp[2][710];
double mem[100010];
double frac[100010];

void precalc(int M, int N)
{
	int t = 0;
	for (int i = 0; i <= N; ++i) dp[t][i] = 0;
	
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			dp[1 - t][j] = (dp[t][j] + (j + 1) / 2.0) * (double)j / (j + 1) + ((dp[t][j + 1]) + j) * 1.0 / (j + 1);
		}
		t = 1 - t;

		mem[i] = dp[t][1];
	}
}

int M, K;

double calc(int c)
{
	ivec muls, divs;
	for (int i = 1; i <= M; ++i) muls.push_back(i);
	for (int i = 1; i <= c; ++i) divs.push_back(i);
	for (int i = 1; i <= M - c; ++i) divs.push_back(i);
	for (int i = 0; i < M; ++i) divs.push_back(K);
	for (int i = 0; i < M - c; ++i) muls.push_back(K - 1);

	double ret = 1;
	int p = 0, q = 0;

	while (p < muls.size() || q < divs.size()) {
		if (q == divs.size() || (ret < 1 && p < muls.size())) {
			ret *= muls[p++];
		} else ret /= divs[q++];
	}
	return ret;
}

int main()
{
	scanf("%d%d", &M, &K);

	precalc(M, 700);

	double ret = 0;

	if (K == 1) {
		ret = mem[M];
	} else {
		int m = M / K;
		double v = calc(m);
		for (int i = m; i <= M; ++i) {
			ret += mem[i] * v;
			if (i == M) break;
			v /= K - 1;
			v /= i + 1;
			v *= M - i;
			//printf("%d %f\n", i, v);
		}
		v = calc(m);
		for (int i = m; i > 0; --i) {
			v *= K - 1;
			v *= i;
			v /= M - i + 1;
			//printf("%d %f\n", i, v);
			ret += mem[i - 1] * v;
		}
	}

	ret *= K;
	printf("%.10f\n", ret);
	return 0;
}