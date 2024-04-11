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

const int LMAX = 30000;

int N, D;
int cnt[30001];
int dp[30001][640];

inline void update(int& d, int v)
{
	d = max(d, v);
}

int main()
{
	scanf("%d%d", &N, &D);

	for (int i = 0; i <= 30000; ++i) cnt[i] = 0;

	for (int i = 0; i < N; ++i) {
		int x;
		scanf("%d", &x);
		++cnt[x];
	}

	const int OFS = 300;
	for (int i = 0; i <= LMAX; ++i) {
		for (int j = 0; j <= 2 * OFS; ++j) {
			dp[i][j] = -1001001001;
		}
	}
	dp[D][OFS] = cnt[D];

	int ret = 0;

	for (int i = D; i <= LMAX; ++i) {
		int m = max(1, D - OFS);
		for (int j = m; j <= D + OFS; ++j) {
			int cv = dp[i][j - D + OFS];
			ret = max(ret, cv);

			if (j >= 2 && i + j - 1 <= LMAX) update(dp[i + j - 1][j - 1 - D + OFS], cv + cnt[i + j - 1]);
			if (          i + j     <= LMAX) update(dp[i + j    ][j     - D + OFS], cv + cnt[i + j    ]);
			if (          i + j + 1 <= LMAX) update(dp[i + j + 1][j + 1 - D + OFS], cv + cnt[i + j + 1]);
		}
	}

	printf("%d\n", ret);

	return 0;
}