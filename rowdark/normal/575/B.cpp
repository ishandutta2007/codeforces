#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

const int N = 1000000 + 10;
const int LOG = 20 + 1;
const int MOD = (int)1e9 + 7;

int n, k;
vector<pair<int, int> > adj[N];
int tag[N];
int depth[N], dir[N];
int father[N][LOG];
long long cost[N];
int dfsOrd[N], tot;

void dfs(int u, int f)
{
	dfsOrd[tot ++] = u;
	father[u][0] = f;
	for(int e = 0; e < adj[u].size(); ++ e) {
		int v = adj[u][e].first;
		if (v == f) continue;
		depth[v] = depth[u] + 1;
		dir[v] = adj[u][e].second;
		dfs(v, u);
	}
}

int jump(int u, int h)
{
	for(int i = 0; h; h >>= 1, ++ i) {
		if (h & 1) {
			u = father[u][i];
		}
	}
	return u;
}

int getLCA(int u, int v)
{
	if (depth[u] < depth[v]) swap(u, v);
	u = jump(u, depth[u] - depth[v]);
	if (u == v) return u;
	for(int i = LOG - 1; i >= 0; -- i) {
		if (father[u][i] != father[v][i]) {
			u = father[u][i];
			v = father[v][i];
		}
	}
	return father[u][0];
}

void solve()
{
	cin >> n;
	for(int i = 0; i < n - 1; ++ i) {
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		--u, --v;
		if (d == 0) {
			adj[u].push_back(make_pair(v, 0));
			adj[v].push_back(make_pair(u, 0));
		} else {
			adj[u].push_back(make_pair(v, 1));
			adj[v].push_back(make_pair(u, 2));
		}
	}
	depth[0] = 0;
	tot = 0;
	dfs(0, 0);
	for(int j = 1; j < LOG; ++ j) {
		for(int i = 0; i < n; ++ i) {
			father[i][j] = father[father[i][j - 1]][j - 1];
		}
	}

	vector<pair<int, int> > upChain, downChain;
	int u = 0, v;
	cin >> k;
	for(int i = 0; i < k; ++ i) {
		scanf("%d", &v);
		--v;
		int lca = getLCA(u, v);
		upChain.push_back(make_pair(u, lca));
		downChain.push_back(make_pair(lca, v));
		u = v;
	}

	long long ret = 0;
	{
		fill(tag, tag + n, 0);
		for(int i = 0; i < upChain.size(); ++ i) {
			tag[upChain[i].first] ++;
			tag[upChain[i].second] --;
		}
		for(int i = n - 1; i >= 0; -- i) {
			int u = dfsOrd[i];
			if (u) {
				tag[father[u][0]] += tag[u];
				if (dir[u] == 1) {
					ret += cost[tag[u]];
				}
			}
		}
	}
	{
		fill(tag, tag + n, 0);
		for(int i = 0; i < downChain.size(); ++ i) {
			tag[downChain[i].second] ++;
			tag[downChain[i].first] --;
		}
		for(int i = n - 1; i >= 0; -- i) {
			int u = dfsOrd[i];
			if (u) {
				tag[father[u][0]] += tag[u];
				if (dir[u] == 2) {
					ret += cost[tag[u]];
				}
			}
		}
	}
	cout << ret % MOD << endl;
}

int main()
{
	cost[0] = 0;
	long long x = 1;
	for(int i = 1; i < N; ++ i) {
		cost[i] = cost[i - 1] + x;
		cost[i] %= MOD;
		x = x * 2 % MOD;
	}
	solve();
	return 0;
}