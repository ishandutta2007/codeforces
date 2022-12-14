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
vector<int> adj[N];
int q[N], h[N], rev[N], par[N];
vector<int> dep[N];
void dfs(int v, int p = -1, int d = 0) {
	h[v] = d;
	par[v] = p;
	for (int u : adj[v])
		if (u != p)
			dfs(u, v, 1 + d);
}
void traverse(int v, int d = 0) {
	map<int, int> is_ch;
	for (int u : adj[v])
		if (u != par[v])
			is_ch[u] = 1;
	for (int j = 0; j < (int) is_ch.size(); ++j) {
		if (!dep[d + 1].size()) {
			cout << "No\n";
			exit(0);
		}
		if (!is_ch[dep[d + 1].back()]) {
			cout << "No\n";
			exit(0);
		}
		traverse(dep[d + 1].back(), d + 1);
	}
	if (!dep[d].size()) {
		cout << "No\n";
		exit(0);
	}
	dep[d].pop_back();
}
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int j = 0; j < n; ++j)
		cin >> q[j], --q[j], rev[q[j]] = j;
	dfs(q[0]);
	if (q[0] != 0) {
		cout << "No\n";
		return 0;
		
	}
	for (int j = 0; j < n; ++j) {
		dep[h[q[j]]].push_back(q[j]);
	}
	for (int j = 0; j < n - 1; ++j)
		if (h[q[j]] > h[q[j + 1]]) {
			cout << "No\n";
			return 0;
		}
	for (int j = 0; j < n + 1; ++j) reverse(ALL(dep[j]));
	if (dep[0].size() != 1) {
		cout << "No\n";
		return 0;
	}
	traverse(dep[0][0], 0);
	cout << "Yes\n";
	return 0;
}