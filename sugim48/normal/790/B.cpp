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
#include <fstream>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; ll w; };

const int MOD = 1000000007;
const int _MOD = 1000000009;
double EPS = 1e-10;
const int INF = INT_MAX / 10;

int N, K;
ll ans = 0;

void dfs(int u, int p, vector<vector<int> >& G, vector<vector<int> >& dp) {
	dp[u][0]++;
	for (int v: G[u]) if (v != p) {
		dfs(v, u, G, dp);
		rep(k, K) dp[u][(k + 1) % K] += dp[v][k];
	}
}

void _dfs(int u, int p, vector<vector<int> >& G, vector<vector<int> >& dp, vector<vector<int> >& _dp) {
	for (int v: G[u]) if (v != p) {
		rep(k, K) _dp[v][(k + 1) % K] += _dp[u][k];
		rep(k, K) _dp[v][(k + 1) % K] += dp[u][(k + 1) % K] - dp[v][k];
		_dfs(v, u, G, dp, _dp);
	}
	int sum = 0;
	rep(k, K) sum += dp[u][k];
	ans += (ll)dp[u][0] * (N - sum) + (ll)_dp[u][0] * sum;
}

int main() {
	cin >> N >> K;
	vector<vector<int> > G(N);
	rep(i, N - 1) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		G[u].pb(v); G[v].pb(u);
	}
	vector<vector<int> > dp(N, vector<int>(K)), _dp = dp;
	dfs(0, -1, G, dp);
	_dfs(0, -1, G, dp, _dp);
	cout << ans / 2 << endl;
}