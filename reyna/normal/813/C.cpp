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
int d0[N], d1[N];
vector<int> adj[N];
void dfs(int v, int d[N], int p = -1) {
	for (int u : adj[v])
		if (u != p)
			d[u] = d[v] + 1, dfs(u, d, v);
}
int main() {
	int n, st;
	cin >> n >> st;
	--st;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, d0);
	dfs(st, d1);
	int mn = 1e9;
	int moves = 0;
	for (int j = 0; j < n; ++j) {
		if (d1[j] == d0[j]) {
			mn = min(mn, d0[j]);
		}
	}
	if (mn < N)
		moves = max(moves, mn * 2);
	for (int j = 0; j < n; ++j)
		if (d1[j] < d0[j])
			moves = max(moves, d0[j] * 2);
	cout << moves << endl;
}