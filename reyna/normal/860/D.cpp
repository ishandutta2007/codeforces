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
int h[N];
vector<int> res[N], adj[N];
void dfs(int v, int p) {
	h[v] = h[p] + 1;
	for (auto u : adj[v]) if (u != p) {
		if (!h[u]) {
			dfs(u, v);
		} else if (h[u] < h[v]) {
			res[v].push_back(u);
		}
	}
	if (v != p) {
		if ((int) res[v].size() % 2 == 1) {
			res[v].push_back(p);
		} else {
			res[p].push_back(v);
		}
	}
	// cerr << v << " " <<  SZ(F[v]) << endl;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int v = 0; v < n; ++v) if (!h[v]) dfs(v, v);
	int cnt = 0;
	
	for (int v = 0; v < n; ++v) {
		for (int j = 0; j + 1 < (int) res[v].size(); j += 2) {
			++cnt;;
		}
	}
	cout << cnt << '\n';
	for (int v = 0; v < n; ++v) {
		for (int j = 0; j + 1 < (int) res[v].size(); j += 2) {
			cout << res[v][j] + 1 << ' ' << v + 1 << ' ' << res[v][j + 1] + 1 << '\n';
		}
	}
}