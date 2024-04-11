
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
#define merge mer
const int N = (int) 1e5 + 6, M = 380, mod = (int) 1e9 + 7;
map<int, int> ind;
int nxt[N][32], msk[N], h[N], sz, mark[N], merge[M][M];
vector<pair<int, int>> adj[N];
map<int, int> edge[N];
int gen(int mask) {
	if (ind.find(mask) != ind.end()) return ind[mask];
	msk[sz] = mask;
	ind[mask] = sz++;
	int cur = ind[mask];
	for (int j = 0; j < 32; ++j)
		if (~mask >> j & 1) {
			int nmask = mask;
			for (int i = 0; i < 32; ++i)
				if (mask >> i & 1)
					nmask |= 1 << (i^j);
			assert(__builtin_popcount(mask) * 2 == __builtin_popcount(nmask));
			nxt[cur][j] = gen(nmask);
		}
	return cur;
}
int dep[N];
int dfs(int v, int lead, int p = -1) {
	if (mark[v] != -1) return 0;
	mark[v] = lead;
	dep[v] = (p == -1 ? 0 : dep[p] + 1);
	int state = 0;
	for (auto e : adj[v]) {
		int u = e.first, w = e.second;
		if (u == p) continue;
		if (mark[u] == lead) {
			int wei = w ^ h[v] ^ h[u];
			if (dep[u] < dep[v]) {
				state = nxt[state][wei];
			}
		} else if (mark[u] == -1) {
			h[u] = h[v] ^ w;
			int x = dfs(u, lead, v);
			state = merge[state][x];
		}
	}
	return state;
}
int state[N], dp[M], odp[M];
vector<int> all[N];
int main() {
	memset(nxt, -1, sizeof nxt);
	ios_base::sync_with_stdio(0);
	gen(1);
	for (int mask = 0; mask <= sz; ++mask)
		for (int j = 0; j < 32; ++j)
			if (nxt[mask][j] == -1)
				nxt[mask][j] = sz;
	for (int i = 0; i < sz; ++i)
		for (int j = 0; j < sz; ++j) {
			if ((msk[i] & msk[j]) != 1) {
				merge[i][j] = sz;
				continue;
			}
			int nmask = 1;
			for (int b = 0; b < 32; ++b) if (msk[j] >> b & 1)
				for (int c = 0; c < 32; ++c) if (msk[i] >> c & 1)
					nmask |= 1 << (b^c);
			merge[i][j] = ind[nmask];
		}
	for (int i = 0; i < sz; ++i)
		merge[i][sz] = merge[sz][i] = sz;
	merge[sz][sz] = sz;
	++sz;
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		edge[u][v] = w;
		edge[v][u] = w;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	memset(mark, -1, sizeof mark);
	mark[0] = N;
	for (auto e : adj[0]) {
		int v = e.first, w = e.second;
		if (mark[v] == -1) {
			h[v] = 0;
			int x = dfs(v, v);
			state[mark[v]] = x;
		}
		all[mark[v]].pb(v);
	}
	
	dp[0] = 1;
	for (int v = 0; v < n; ++v) {
		if ((int) all[v].size() >= 1) {
			memcpy(odp, dp, sizeof dp);
			memset(dp, 0, sizeof dp);
			for (int mask = 0; mask < sz; ++mask) {
				if ((int) all[v].size() == 2) {
					int w = edge[0][all[v][0]] ^ edge[0][all[v][1]] ^ edge[all[v][0]][all[v][1]];
					int nmask = nxt[merge[state[v]][mask]][w];
					dp[nmask] = (dp[nmask] + odp[mask]) % mod;
				}
				dp[mask] = (dp[mask] + odp[mask]) % mod;
				for (int x : all[v]) {
					int nmask = merge[state[v]][mask];
					dp[nmask] = (dp[nmask] + odp[mask]) % mod;
				}
			}
		}
	}
	int res = 0;
	for (int mask = 0; mask < sz - 1; ++mask) res = (res + dp[mask]) % mod;
	cout << res << endl;
		
}