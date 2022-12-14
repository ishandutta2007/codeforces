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

const int inf = (int) 1e9, N = (int) 3e5 + 6, K = 105, mod = (int) 0;
int p[N], l[N], c[N], cap[K][K], mark[K], src, snk, pr[N], cnt;
int dfs(int v, int f = 1e9) {
	if (v == snk) return f;
	if (mark[v]++) return 0;
	for (int u = 0; u < cnt; ++u) if (u != v && cap[v][u]) {
		int x = dfs(u, min(f, cap[v][u]));
		if (x) {
			cap[v][u] -= x;
			cap[u][v] += x;
			return x;
		}
	}
	return 0;
}
int n, k;
void add_edge(int u, int v, int w) {
	cap[u][v] += w;
}
int check(int lim) {
	cnt = n + 2;
	src = n, snk = n + 1;
	for (int use = 0; use <= 1; ++use) {
		memset(cap, 0, sizeof cap);
		int sum = 0, mx = 0, ind = -1;
		for (int j = 0; j < n; ++j) {
			if (l[j] <= lim) {
				if (c[j] == 1) {
					if (mx < p[j]) {
						mx = max(mx, p[j]);
						ind = j;
					}
				} else {
					sum += p[j];
					if (c[j] & 1) {
						add_edge(src, j, p[j]);
					} else {
						add_edge(j, snk, p[j]);
					}
				}
			}
		}
		if (use && ind != -1) {
			sum += mx;
			add_edge(src, ind, mx);
		}
		for (int i = 0; i < n; ++i) if (l[i] <= lim)
			for (int j = 0; j < n; ++j) if (l[j] <= lim)
				if ((c[i] % 2 == 1) && (c[j] % 2 == 0) && pr[c[i] + c[j]]) {
					add_edge(i, j, inf);
				}
		int res = 0;
		while (true) {
			memset(mark, 0, sizeof mark);
			int x = dfs(src);
			res += x;
			if (!x) break;
		}
		if (sum - res >= k) return 1;
	}
	return 0;
}
int main() {
	pr[0] = pr[1] = 0;
	for (int j = 2; j < N; ++j) pr[j] = 1;
	for (int j = 2; j < N; ++j)
		if (pr[j] == 1)
			for (int k = j + j; k < N; k += j)
				pr[k] = 0;
	cin >> n >> k;
	for (int j = 0; j < n; ++j)
		cin >> p[j] >> c[j] >> l[j];
	int bl = 0, br = n + 1;
	while (bl < br - 1) {
		int bm = bl + br >> 1;
		if (check(bm)) {
			br = bm;
		} else {
			bl = bm;
		}
	}
	cout << (br > n ? -1 : br) << endl;
}