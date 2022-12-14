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

const int N = (int) 3e5 + 5, M = 20, K = M * (M + 1) / 2, mod = (int) 0;
int res[N], nxt[N][M], best[K], fs[M], qx[N], qy[N], a[N], rx[K], ry[K], id[M][M], go[K][K], fst[K];
vector<int> queries[N];
int main() {
	ios_base::sync_with_stdio(0);
	int cc = 0;
	for (int i = 0; i < M; ++i)
		for (int j = i + 1; j < M; ++j) {
			rx[cc] = i;
			ry[cc] = j;
			id[j][i] = cc;
			id[i][j] = cc;
			++cc;
		}
	int n, q;
	cin >> n >> q;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int j = 0; j < K; ++j)
		fst[j] = n;
	for (int j = 0; j < M; ++j) fs[j] = n;
	for (int i = 0; i < M; ++i) nxt[n][i] = n;
	for (int j = n - 1; j >= 0; --j) {
		int cur = a[j];
		for (int i = 0; i < M; ++i) nxt[j][i] = n;
		for (int x = 0; x < M; ++x) if (cur >> x & 1) {
			for (int y = x + 1; y < M; ++y)
				if ((cur >> y & 1))
					fst[id[x][y]] = j;
		}
		for (int x = 0; x < M; ++x) {
			if (cur >> x & 1) {
				nxt[j][x] = j;
				for (int y = 0; y < M; ++y) if (x != y) 
					nxt[j][y] = min(nxt[j][y], fst[id[x][y]]);
			}
		}
		for (int x = 0; x < M; ++x)
			if (cur >> x & 1) {
				for (int y = 0; y < M; ++y) {
					nxt[j][y] = min(nxt[j][y], nxt[fs[x]][y]);	
				}
			}
		for (int x = 0; x < M; ++x)
			if (cur >> x & 1)
				fs[x] = j;
	}
	for (int j = 0; j < q; ++j) {
		cin >> qx[j] >> qy[j], --qx[j], --qy[j];
		int x = qx[j], y = qy[j];
		int curx = a[x];
		int cury = a[y];
		int can = 0;
		for (int i = 0; i < M; ++i)
			if (nxt[x][i] <= y && (cury >> i & 1))
				can = 1;
		cout << (can ? "Shi\n" : "Fou\n");
	}
}