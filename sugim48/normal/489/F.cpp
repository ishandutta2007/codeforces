#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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

int calc(int k) {
	return (ll)k * (k - 1) / 2;
}

int main() {
	int n, m, mod; cin >> n >> m >> mod;
	vector<int> a(n);
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++)
			if (s[j] == '1') a[j]++;
	}
	int k0 = 0, k1 = 0;
	for (int j = 0; j < n; j++)
		if (a[j] == 0) k0++;
		else if (a[j] == 1) k1++;
	vector< vector<ll> > dp(n + 1, vector<ll>(n + 1));
	dp[k0][k1] = 1;
	for (int i = 0; i < n - m; i++) {
		vector< vector<ll> > _dp(n + 1, vector<ll>(n + 1));
		for (int k0 = 0; k0 <= n; k0++)
			for (int k1 = 0; k1 <= n; k1++) {
				if (k0 + k1 > n) continue;
				if (dp[k0][k1] == 0) continue;
				if (k0 >= 2) _dp[k0 - 2][k1 + 2] = (_dp[k0 - 2][k1 + 2] + dp[k0][k1] * calc(k0)) % mod;
				if (k1 >= 2) _dp[k0][k1 - 2] = (_dp[k0][k1 - 2] + dp[k0][k1] * calc(k1)) % mod;
				if (k0 >= 1 && k1 >= 1) _dp[k0 - 1][k1] = (_dp[k0 - 1][k1] + dp[k0][k1] * k0 * k1) % mod;
			}
		dp = _dp;
	}
	cout << dp[0][0] << endl;
}