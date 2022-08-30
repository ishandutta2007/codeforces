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
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N;
i64 C[4040][4040];

i64 dp1[4040], dp2[4040];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i <= N; ++i) C[0][i] = 0;
	C[0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= N; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}

	dp1[0] = 1;
	dp2[0] = 1;
	for (int i = 1; i <= N; ++i) {
		// equiv
		dp1[i] = 0;
		for (int j = 1; j <= i; ++j) ADD(dp1[i], dp1[i - j] * C[i - 1][j - 1]);

		// johnny
		dp2[i] = 0;
		for (int j = 1; j <= i; ++j) ADD(dp2[i], dp2[i - j] * C[i - 1][j - 1]);
		ADD(dp2[i], dp2[i - 1]);
	}
	i64 ans = dp2[N] - dp1[N] + MOD;
	ans %= MOD;
	cout << ans << endl;

	return 0;
}