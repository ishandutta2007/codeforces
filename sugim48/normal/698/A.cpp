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
#include <random>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

int INF = INT_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int& x: a) cin >> x;
	vector<int> dp(3, INF);
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		vector<int> _dp(3, INF);
		_dp[0] = min(dp[0], min(dp[1], dp[2])) + 1;
		if (a[i]>>0 & 1) _dp[1] = min(dp[0], dp[2]);
		if (a[i]>>1 & 1) _dp[2] = min(dp[0], dp[1]);
		dp = _dp;
	}
	int ans = min(dp[0], min(dp[1], dp[2]));
	cout << ans << endl;
}