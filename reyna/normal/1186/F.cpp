
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

const int N = (int) 3e6 + 6, mod = (int) 0;
int deg[N];
int mark[N], eu[N], ev[N];
vector<int> adj[N];
vector<int> edges;
void dfs(int v) {
	while ((int) adj[v].size()) {
		int e = adj[v].back();
		if (mark[e]) {
			adj[v].pop_back();
		} else {
			int u = eu[e] ^ ev[e] ^ v;
			mark[e] = 1;
			dfs(u);
			edges.pb(e);
		}
	}
}
int use[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		int &u = eu[j], &v = ev[j];
		cin >> u >> v;
		--u, --v;
		adj[u].pb(j);
		adj[v].pb(j);
		deg[u]++;
		deg[v]++;
	}
	vector<int> odd;
	for (int v = 0; v < n; ++v)
		if (deg[v] & 1)
			odd.pb(v);
	int en = m;
	for (int j = 0; j < (int) odd.size(); j += 2) {
		eu[en] = odd[j];
		ev[en] = odd[j + 1];
		adj[eu[en]].pb(en);
		adj[ev[en]].pb(en);
		++en;
	}
	for (int v = 0; v < n; ++v)
		dfs(v);
	int turn = 1;
	int s = (int) edges.size();
	for (int j = 0; j < (int) s; ++j) {
		if (edges[j % s] >= m) {
			use[edges[(j - 1 + s) % s]] = 1;
			use[edges[(j + 1 + s) % s]] = 1;
			turn = 1;
		} else {
			if (turn) {
				use[edges[j % s]] = 1;
			}
			turn ^= 1;
		}
	}
	int cnt = 0;
	for (int e = 0; e < m; ++e) cnt += use[e];
	assert(cnt <= (n + m + 1) / 2);
	int additional = (n + m + 1) / 2 - cnt;
	cout << min(m, cnt + additional) << '\n';
	for (int e = 0; e < m; ++e) {
		if (use[e]) {
			cout << eu[e] + 1 << ' ' << ev[e] + 1 << '\n';
		} else {
			if (additional) {
				cout << eu[e] + 1 << ' ' << ev[e] + 1 << '\n';
				--additional;
			}
		}
	}
}