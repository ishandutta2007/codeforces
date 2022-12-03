#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
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
struct edge { int u, v; ll w; int i; bool used; };
 
int MOD = 1000000007;

int main() {
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	if (a < b) {
		a--;
		n = b - 1;
	}
	else {
		a = n - a;
		n -= b;
	}
	vector<ll> dp(n);
	dp[a] = 1;
	while (k--) {
		vector<ll> _dp(n);
		for (int i = 0; i < n; i++) {
			int _i = max(0, i * 2 - n + 1);
			_dp[_i] = (_dp[_i] + dp[i]) % MOD;
		}
		for (int i = 0; i < n - 1; i++)
			_dp[i + 1] = (_dp[i + 1] + _dp[i]) % MOD;
		for (int i = 0; i < n; i++)
			_dp[i] = (_dp[i] - dp[i]) % MOD;
		dp = _dp;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans = (ans + dp[i]) % MOD;
	cout << (ans + MOD) % MOD << endl;
}