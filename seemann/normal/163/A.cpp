#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

#define ll long long int
#define FOR(a, b) for (int a = 0; a < b; a++)
#define clr(a) memset(a, 0, sizeof(a))

using namespace std;
const int INF = 1000000000;
const double EPS = 0.000000001;
const int MAXN = 5001;
const int MOD = 1000000007;

int dp[MAXN][MAXN];
//int d2[MAXN];



int main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	string a, b;
	cin >> a >> b;
	clr(dp);

	FOR(i, b.length()) {
		FOR(j, a.length()) {
			if (b[i] != a[j])
				continue;
			if (j != 0 && i != 0)
				dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
			dp[i][j] += 1;
			dp[i][j] %= MOD;
		}
		if (i > 0)
		FOR(j, a.length())
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
	}

	int ans = 0;
		FOR(j, a.length()){
			ans = (ans + dp[b.length() - 1][j]) % MOD;
		}
	cout << ans;
}