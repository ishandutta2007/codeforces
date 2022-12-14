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
int mark[N], d[N], s[N], t[N];
vector<int> adj[N], res;
int dfs(int v, int p = -1) {
	mark[v] = 1;
	int parity = d[v];
	for (int e : adj[v]) {
		int u = s[e] ^ t[e] ^ v;
		if (u != p && !mark[u]) {
			int x = dfs(u, v);
			parity ^= x;
			if (x) {
				res.pb(e);
			}
		}
	}
	return parity;
}
int main() {
	int n, m;
	cin >> n >> m;
	int o = 0;
	for (int j = 0; j < n; ++j) {
		cin >> d[j];
		if (d[j] != -1) o += d[j];	
	}
	if (o % 2 == 1) {
		for (int j = 0; j < n; ++j) {
			if (d[j] == -1) {
				d[j] = 1;
				o = -1;
				break;
			}
		}
		if (o != -1) {
			cout << -1 << endl;
			return 0;
		}
	}
	{
		for (int j = 0; j < n; ++j) if (d[j] == -1) d[j] = 0;
	}
	for (int j = 0; j < m; ++j) {
		int &u = s[j], &v = t[j];
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(j);
		adj[v].push_back(j);
	}
	dfs(0);
	cout << (int) res.size() << '\n';
	for (int e : res) cout << e + 1 << '\n';
}