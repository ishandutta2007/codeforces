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
const int N = (int) 1e6 + 6, mod = (int) 1e9 + 7;

int a[N], eu[N], ev[N], p2[N], mark[N], col[N];
vector<int> adj[N];
map<int, vector<int>> all;
int dfs(int v, int c = 1) {
	if (mark[v]) {
		if (c != col[v]) {
			return 0;
		}
		return 1;
	}
	mark[v] = 1;
	col[v] = c;
	int res = 1;
	for (int u : adj[v])
		res &= dfs(u, 3 - c);
	return res;
}
int32_t main() {
	p2[0] =1 ;
	for (int j =1 ; j < N; ++j)
		p2[j] = p2[j -1 ] * 2 % mod;
	ios_base::sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int j = 0; j < m; ++j) {
		int &u = eu[j], &v = ev[j];
		cin >> u >> v;
		--u, --v;
		all[a[u] ^ a[v]].push_back(j);
	}
	int res = 0;
	int rest = (1ll << k) - (int) all.size();
	for (auto x : all) {
		vector<int> cur = x.second;
		vector<int> everyone;
		for (int j : cur) {
			int u = eu[j], v = ev[j];
			everyone.pb(u);
			everyone.pb(v);
		}
		for (int x : everyone) mark[x] = 0, col[x] = 0, adj[x].clear();
		int comp = 0;
		for (int j : cur) {
			int u = eu[j], v = ev[j];
			adj[u].pb(v);
			adj[v].pb(u);
		}
		int fail = 0;
		for (int x : everyone)
			if (!mark[x]) {
				comp++;
				if (dfs(x) == 0) {
					fail = 1;
				}
			}
		if (fail) continue;
		int cnt = 0;
		for (int x : everyone) {
			cnt += mark[x];
			mark[x] = 0;
		}
		comp += n - cnt;
		res = (res + p2[comp]) % mod;
	}
	res = (res + (rest % mod) * p2[n]) % mod;
	cout << res << endl;
}