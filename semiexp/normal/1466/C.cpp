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

int T, N;
char S[101010];

int dp[101010][2][2];

int main()
{
	scanf("%d", &T);
	for (;T--;) {
		scanf("%s", S);
		N = strlen(S);

		for (int i = 0; i <= N; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					dp[i][j][k] = (i == 0 ? 0 : (N + 100));
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					for (int l = 0; l < 2; ++l) {
						if (i >= 2 && j == 0 && l == 0 && S[i - 2] == S[i]) continue;
						if (i >= 1 && k == 0 && l == 0 && S[i - 1] == S[i]) continue;
						dp[i + 1][k][l] = min(dp[i + 1][k][l], dp[i][j][k] + l);
					}
				}
			}
		}
		int ret = N + 100;
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k) ret = min(ret, dp[N][j][k]);
		printf("%d\n", ret);
	}

	return 0;
}