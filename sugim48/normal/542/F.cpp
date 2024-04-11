#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
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

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;

int main() {
	int N, M; cin >> N >> M;
	vector<vector<int> > as(M);
	while (N--) {
		int j, x; cin >> j >> x;
		as[j - 1].pb(x);
	}
	vector<int> dp(1001);
	for (vector<int> a: as) {
		vector<int> _dp(1001);
		rep(i, 1001) _dp[(i + 1) / 2] = max(_dp[(i + 1) / 2], dp[i]);
		for (int x: a)
			for (int i = 999; i >= 0; i--)
				_dp[i + 1] = max(_dp[i + 1], _dp[i] + x);
		dp = _dp;
	}
	cout << dp[1] << endl;
}