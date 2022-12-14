
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

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 998244353;
int dp[N][3];
vector<int> adj[N];
// 0 died before parent
// 1 died after parent
void dfs(int v, int p = -1) {
	int par_pos = 0;
	int m = (int) adj[v].size();
	for (int j = 0; j < m; ++j)
		if (adj[v][j] == p)
			par_pos = j;
	for (int u : adj[v])
		if (u != p)
			dfs(u, v);
	vector<int> ls(m + 1), rs(m + 1);
	ls[0] = 1;
	rs[m - 1] = 1;
	int cnt = 0;
	vector<int> ch;
	for (int u : adj[v]) if (u != p) {
		ls[cnt + 1] = (LL) ls[cnt] * (dp[u][0] + dp[u][2]) % mod;	
		++cnt;
		ch.pb(u);
	}
	cnt = m - 1;
	for (int j = m - 1; j >= 0; --j) if (adj[v][j] != p) {
		int u = adj[v][j];
		rs[cnt - 1] = ((LL) rs[cnt] * (dp[u][1] + dp[u][0]) % mod);
		--cnt;
	}
	dp[v][2] = ls[par_pos] * (LL) rs[par_pos] % mod;
	{
		// died before parent
		for (int j = 0; j < par_pos; ++j) {
			dp[v][0] = (dp[v][0] + (LL) ls[j] * rs[j + 1] % mod * dp[ch[j]][1]) % mod;
		}
	}
	{
		// died after parent
		for (int j = par_pos; j < m - 1; ++j) {
			dp[v][1] = (dp[v][1] + (LL) ls[j] * rs[j + 1] % mod * dp[ch[j]][1]) % mod;	
		}
		dp[v][1] = (dp[v][1] + (LL) ls[m - 1]) % mod;
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	adj[n - 1].pb(-1);
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(n - 1);
	cout << dp[n - 1][1] % mod << endl;
	
}