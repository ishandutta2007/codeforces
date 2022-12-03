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
#include <random>
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
typedef pair<int, ll> i_ll;
struct edge { int u, v; ll w; };

double INF = DBL_MAX / 10;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

void dfs(int u, vector<vector<int> >& G, vector<int>& a, vector<vector<int> >& dp) {
	dp[u][a[u]] = 1;
	for (int v: G[u]) {
		dfs(v, G, a, dp);
		dp[u][1] = (ll)dp[u][1] * (dp[v][0] + dp[v][1]) % MOD;
		dp[u][1] = (dp[u][1] + (ll)dp[u][0] * dp[v][1]) % MOD;
		dp[u][0] = (ll)dp[u][0] * (dp[v][0] + dp[v][1]) % MOD;
	}
}

int main() {
	int N; cin >> N;
	vector<vector<int> > G(N);
	for (int u = 1; u < N; u++) {
		int p; scanf("%d", &p);
		G[p].push_back(u);
	}
	vector<int> a(N);
	for (int u = 0; u < N; u++)
		scanf("%d", &a[u]);
	vector<vector<int> > dp(N, vector<int>(2));
	dfs(0, G, a, dp);
	cout << dp[0][1] << endl;
}