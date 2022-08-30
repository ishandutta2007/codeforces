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

int N, Ai[1010];

int dp[1010][3];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", Ai + i);

	for (int i = 0; i < 3; ++i) dp[0][i] = 10000;
	dp[0][0] = 0;

	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) if ((Ai[i - 1] & j) == j) {
			dp[i][j] = 10000;
			for (int k = 0; k < 3; ++k) if ((j & k) == 0) {
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + (j == 0 ? 1 : 0));
			}
		} else dp[i][j] = 10000;
	}
	int ret = min(dp[N][0], min(dp[N][1], dp[N][2]));
	printf("%d\n", ret);

	return 0;
}