#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	vector<vector<ll> > c(4001, vector<ll>(4001));
	for (int i = 0; i <= 4000; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	int n; cin >> n;
	vector<ll> dp(4001);
	dp[0] = 1;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll sum = 0;
		for (int j = 0; j <= i; j++)
			sum = (sum + dp[j]) % MOD;
		ans = (ans + sum * c[n][i]) % MOD;
		vector<ll> _dp(4001);
		for (int j = 0; j <= i; j++) {
			_dp[j + 1] = (_dp[j + 1] + dp[j]) % MOD;
			_dp[j] = (_dp[j] + dp[j] * j) % MOD;
		}
		dp = _dp;
	}
	cout << ans << endl;
}