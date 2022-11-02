#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 40

ll dp[N][N];

int n, h;

ll get(int n, int h) {
	if (n == 0) return 1;
	if (h == 0) return 0;
	if (~dp[n][h]) return dp[n][h];
	ll &ret = dp[n][h]; ret = 0;
	for (int i = 0; i < n; i ++) ret += get(i, h - 1) * get(n - i - 1, h - 1);
	return ret;
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d %d", &n, &h);
	printf("%I64d\n", get(n, n) - get(n, h - 1) );
}