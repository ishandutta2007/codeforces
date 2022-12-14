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

const int N = (int) 2e5 + 5, mod = (int) 0;
vector<int> id[N], f[N];
vector<int> ed[N];
int eu[N], ev[N], ew[N], dp[N];
void update_max(int m, int val, int v) { ++m;
	while (m < (int) f[v].size()) {
		f[v][m] = max(f[v][m], val);
		m += m & -m;
	}
}
int get_max(int m, int v) { ++m;
	int res = 0;
	while (m > 0) {
		res = max(res, f[v][m]);
		m -= m & -m;
	}
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		int &u = eu[j], &v = ev[j], &w = ew[j];
		cin >> u >> v >> w;
		--u, --v;
		id[v].pb(j);
		ed[w].pb(j);
	}
	for (int v = 0; v < n; ++v) {
		for (int j = 0; j < (int) id[v].size() + 3; ++j) f[v].pb(0);	
	}
	for (int wei = 0; wei < N; ++wei) {
		reverse(ALL(ed[wei]));
		for (int e : ed[wei]) {
			int u = eu[e], v = ev[e];
			int r = upper_bound(id[u].begin(), id[u].end(), e) - id[u].begin();
			dp[e] = max(dp[e], get_max(r - 1, u) + 1);
			int pos = lower_bound(id[v].begin(), id[v].end(), e) - id[v].begin();
			update_max(pos, dp[e], v);
		}
	}
	int res = 0;
	for (int e = 0; e < m; ++e) res = max(res, dp[e]);
	cout << res << endl;
	
}