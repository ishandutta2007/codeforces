#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <list>
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
struct edge { ll B, T, F, P; };

unsigned MOD = 1234567891;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 10;

int main() {
	int n, t; double p;
	cin >> n >> p >> t;
	vector<double> dp(n + 1);
	dp[0] = 1;
	while (t--) {
		vector<double> _dp(n + 1);
		for (int i = 0; i < n; i++) {
			_dp[i] += (1 - p) * dp[i];
			_dp[i + 1] += p * dp[i];
		}
		_dp[n] += dp[n];
		dp = _dp;
	}
	double e = 0;
	for (int i = 0; i <= n; i++)
		e += dp[i] * i;
	printf("%.10f\n", e);
}