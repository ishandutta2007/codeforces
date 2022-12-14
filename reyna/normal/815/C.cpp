// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;
#define int long long
const int N = (int) 5005, mod = (int) 0;
int dp[N][N][2], odp[N][2], sz[N], cost[N], discount[N];
vector<int> adj[N];
void dfs(int v) {
	dp[v][0][0] = 0;
	dp[v][1][0] = cost[v];
	dp[v][1][1] = cost[v] - discount[v];
	sz[v] = 1;
	for (int u : adj[v]) {
		dfs(u);
		for (int pick = 0; pick <= sz[v]; ++pick) odp[pick][0] = dp[v][pick][0], odp[pick][1] = dp[v][pick][1], dp[v][pick][0] = dp[v][pick][1] = 1e9 + 10;
		for (int pu = 0; pu <= sz[u]; ++pu)
			for (int pv = 0; pv <= sz[v]; ++pv)
				for (int a = 0; a <= 1; ++a)
					for (int b = 0; b <= 1; ++b) {
						if (a == 0 && b == 1) continue;
						dp[v][pu + pv][a] = min(dp[v][pu + pv][a], dp[u][pu][b] + odp[pv][a]);
					}
		sz[v] += sz[u];	
	}
	
}
int32_t main() {
	memset(dp, 63, sizeof dp);
	int n, budget;
	cin >> n >> budget;
	for (int j = 0; j < n; ++j) {
		cin >> cost[j] >> discount[j];
		if (j >= 1) {
			int p;
			cin >> p;
			--p;
			adj[p].push_back(j);
		}
	}
	dfs(0);
	int res = 0;
	for (int s = 0; s <= n; ++s)
		if (min(dp[0][s][0], dp[0][s][1]) <= budget)
			res = max(res, s);
	cout << res << endl;
}