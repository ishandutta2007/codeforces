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

const int N = (int) 1e6 + 6, mod = (int) 0;
int par[N], deg[N];
vector<int> adj[N];
void dfs(int v, int p = -1) {
	par[v] = p;
	for (int u : adj[v]) if (u != p)
		dfs(u, v);
}
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		deg[u]++;
		deg[v]++;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int mx = 0, cnt = 0;
	for (int j = 0; j < n; ++j) {
		if (deg[mx] < deg[j])
			mx = j;
	}
	for (int j = 0; j < n; ++j) {
		if (j != mx && deg[j] > 2) {
			cout << "No\n";
			return 0;
		}
		if (j != mx && deg[j] == 1) {
			++cnt;
		}
	}
	dfs(mx);
	cout << "Yes\n";
	cout << cnt << '\n';
	for (int v = 0; v < n; ++v)
		if (v != mx && deg[v] == 1) {
			cout << mx + 1 << ' ' << v + 1 << '\n';
		}
	
	
}