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
int X[101];
double dp[101][101010];

void append(int l, int r, int k, double v)
{
	// [l, r] += k
	dp[k][l] += v;
	dp[k][r + 1] -= v;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%d", X + i);
		--X[i];
	}
	if (M == 1) {
		puts("1");
		return 0;
	}

	dp[0][0] = 1.0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i * M; ++j) {
			append(j + 0, j + X[i] - 1, i + 1, dp[i][j] / (M - 1));
			append(j + X[i] + 1, j + M - 1, i + 1, dp[i][j] / (M - 1));
		}
		for (int j = 1; j <= (i + 1) * M; ++j) dp[i + 1][j] += dp[i + 1][j - 1];
	}

	double ret = 0;
	int S = 0;
	for (int i = 0; i < N; ++i) S += X[i];
	for (int i = 0; i < S; ++i) ret += dp[N][i];

	printf("%.10f\n", 1.0 + ret * (M - 1));

	return 0;
}