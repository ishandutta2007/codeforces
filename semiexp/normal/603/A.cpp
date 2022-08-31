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

int N;
char S[101010];
int dp[101010][6];

int main()
{
	scanf("%d%s", &N, S);
	for (int i = 0; i < 6; ++i) dp[0][i] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 6; ++j) dp[i + 1][j] = (dp[i][j]);
		if (S[i] == '1') {
			dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + 1);
			dp[i + 1][3] = max(dp[i + 1][3], dp[i][2] + 1);
			dp[i + 1][3] = max(dp[i + 1][3], dp[i][1] + 1);
			dp[i + 1][5] = max(dp[i + 1][5], dp[i][4] + 1);
			dp[i + 1][5] = max(dp[i + 1][5], dp[i][3] + 1);
			dp[i + 1][5] = max(dp[i + 1][5], dp[i][0] + 1);
		}
		if (S[i] == '0') {
			dp[i + 1][1 ^ 1] = max(dp[i + 1][1 ^ 1], dp[i][0 ^ 1] + 1);
			dp[i + 1][3 ^ 1] = max(dp[i + 1][3 ^ 1], dp[i][2 ^ 1] + 1);
			dp[i + 1][3 ^ 1] = max(dp[i + 1][3 ^ 1], dp[i][1 ^ 1] + 1);
			dp[i + 1][5 ^ 1] = max(dp[i + 1][5 ^ 1], dp[i][4 ^ 1] + 1);
			dp[i + 1][5 ^ 1] = max(dp[i + 1][5 ^ 1], dp[i][3 ^ 1] + 1);
			dp[i + 1][5 ^ 1] = max(dp[i + 1][5 ^ 1], dp[i][0 ^ 1] + 1);
		}
	}
	int ret = 0;
	for (int i = 1; i <= N; ++i) for (int j = 0; j < 6; ++j) ret = max(ret, dp[i][j]);
	printf("%d\n", ret);

	return 0;
}