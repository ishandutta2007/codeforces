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

const int INF = 2100000000;

int N, A[4040];
int dp[2][4040][4040];
int S[4040];

int sum(int L, int R) // [L, R)
{
	return S[R] - S[L];
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", A + i);
	}
	S[0] = 0;
	for (int i = 1; i <= N; ++i) S[i] = S[i - 1] + A[i - 1];

	int t = 0;
	for (int T = 100; T >= 1; --T) {
		int len = N;
		for (int i = 1; i < T; ++i) len -= i;
		for (int w = T; w <= len; ++w) {
			int lmin = max(0, -T + (N - w) / 2 - 1);
			int lmax = min(N - w, T + (N - w) / 2);
			for (int l = lmin; l <= lmax; ++l) {
				int r = l + w;

				{
					int ans = -INF;
					if (l + T <= r) ans = max(ans, sum(l, l + T) - (r - l - T >= T ? dp[t][r][l + T] : 0));
					if (l + T + 1 <= r) ans = max(ans, sum(l, l + T + 1) - (r - l - (T + 1) >= T + 1 ? dp[1 - t][r][l + T + 1] : 0));
					dp[t][l][r] = ans;
				}
				{
					int ans = -INF;
					if (l + T <= r) ans = max(ans, sum(r - T, r) - (r - l - T >= T ? dp[t][l][r - T] : 0));
					if (l + T + 1 <= r) ans = max(ans, sum(r - T - 1, r) - (r - l - (T + 1) >= T + 1 ? dp[1 - t][l][r - T - 1] : 0));
					dp[t][r][l] = ans;
				}
			//	printf("%d %d %d: %d\n", T, l, r, dp[t][l][r]);
			//	printf("%d %d %d: %d\n", T, r, l, dp[t][r][l]);
			}
		}
		t = 1 - t;
	}
	printf("%d\n", dp[1 - t][0][N]);

	return 0;
}