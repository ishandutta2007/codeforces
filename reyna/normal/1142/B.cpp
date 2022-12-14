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

const int N = (int) 2e5 + 5, L = 18, mod = (int) 0;
int nxt[N][L], mn[N][L], width[N], after[N], a[N], cur[N], p[N], last[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int j = 0; j < n; ++j) cin >> p[j], --p[j];
	for (int j = 0; j < n; ++j)
		after[p[j]] = p[(j + 1) % n];
	for (int j = 0; j < m; ++j) cin >> a[j], --a[j];
	for (int j = 0; j < n; ++j) last[j] = m;
	for (int j = m - 1; j >= 0; --j) {
		int x = a[j];
		nxt[j][0] = last[after[x]];
		last[x] = j;		
	}
	nxt[m][0] = m;
	for (int j = 1; j < L; ++j)
		for (int v = 0; v <= m; ++v)
			nxt[v][j] = nxt[nxt[v][j - 1]][j - 1];
	for (int v = 0; v <= m; ++v)
		cur[v] = v;
	for (int j = 0; j < L; ++j)
		if ((n - 1) >> j & 1)
			for (int v = 0; v < m; ++v)
				cur[v] = nxt[cur[v]][j];
	for (int v = 0; v <= m; ++v) {
		mn[v][0] = cur[v];
	}
	for (int j = 1; j < L; ++j)
		for (int v = 0; v + (1 << j) <= m; ++v)
			mn[v][j] = min(mn[v][j - 1], mn[v + (1 << j - 1)][j - 1]);
	for (int j = 2; j < N; ++j)
		width[j] = width[j >> 1] + 1;
	for (int j = 0; j < q; ++j) {
		int xl, xr;
		cin >> xl >> xr;
		--xl;
		int w = width[xr - xl];
		int best = min(mn[xl][w], mn[xr - (1 << w)][w]);
		
		cout << (best < xr);
	}
	
	
	
}