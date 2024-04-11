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
char in[21][101010];
int bits[101010];
int dp[1 << 20][21];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%s", in[i]);
	for (int i = 0; i < M; ++i) {
		int v = 0;
		for (int j = 0; j < N; ++j) v |= (in[j][i] - '0') << j;
		bits[i] = v;
	}
	for (int i = 0; i < (1 << N); ++i) {
		for (int j = 0; j <= N; ++j) dp[i][j] = 0;
	}
	for (int i = 0; i < M; ++i) dp[bits[i]][0] += 1;

	for (int i = 0; i < N; ++i) {
		for (int j = N; j >= 1; --j) {
			for (int k = 0; k < (1 << N); ++k) if (!(k & (1 << i))) {
				int l = k | (1 << i);
				
				int k2 = dp[k][j] + dp[l][j - 1];
				int l2 = dp[l][j] + dp[k][j - 1];
				dp[k][j] = k2;
				dp[l][j] = l2;
			}
		}
	}

	int ans = N * M;
	for (int i = 0; i < (1 << N); ++i) {
		int tmp = 0;
		for (int j = 0; j <= N; ++j) {
		//	printf("%d %d: %d\n", i, j, dp[i][j]);
			tmp += min(j, N - j) * dp[i][j];
		}
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}