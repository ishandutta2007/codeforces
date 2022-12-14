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

const int N = (int) 1e5 + 5, mod = (int) 0;
int match[N], p[N], taken[N];
set<pair<int, int>> st;
int do_turn(int x) {
	cout << x + 1 << endl;
	int y;
	cin >> y;
	--y;
	taken[x] = taken[y] = 1;
	return y;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < 2 * n; ++j) cin >> p[j];
	memset(match, -1, sizeof match);
	for (int j = 0; j < m; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		match[u] = v;
		match[v] = u;
	}
	int t;
	cin >> t;
	if (t == 1) {
		for (int v = 0; v < 2 * n; ++v) if (!taken[v]) {
			int u = match[v];
			if (u == -1 && !taken[match[v]]) continue;
			if ((p[u] == p[v] && v < u) || p[v] - p[u] > 0) {
				do_turn(v);
			}
		}
		while (true) {
			int mx = -1;
			for (int v = 0; v < 2 * n; ++v)
				if (!taken[v]) {
					if (mx == -1 || p[mx] < p[v])
						mx = v;
				}
			if (mx == -1) break;
			do_turn(mx);
		}
	} else {
		int turns = 0;
		while (turns < n) {
			int v;
			cin >> v;
			--v;
			taken[v] = 1;
			if (match[v] == -1) break;
			++turns;
			taken[match[v]] = 1;
			cout << match[v] + 1 << endl;
		}
		if (turns >= n) return 0;
		for (int v = 0; v < 2 * n; ++v) if (!taken[v]) {
			int u = match[v];
			if (u == -1 && !taken[match[v]]) continue;
			if ((p[u] == p[v] && v < u) || p[v] - p[u] > 0) {
				do_turn(v);
				++turns;
			}
		}
		while (true) {
			int mx = -1;
			for (int v = 0; v < 2 * n; ++v)
				if (!taken[v]) {
					if (mx == -1 || p[mx] < p[v])
						mx = v;
				}
			if (mx == -1) break;
			if (turns == n - 1) {
				cout << mx + 1 << endl;
				return 0;
			} else {
				do_turn(mx);
			}
			++turns;
		}
	}
}