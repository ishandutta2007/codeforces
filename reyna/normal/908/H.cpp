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

const int N = (int) 55, M = 23, mod = (int) (1 << 23) * 17 * 7 + 1;
struct dsu {
	int par[N];
	dsu() {
		for (int j = 0; j < N; ++j) par[j] = j;	
	}
	int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
	void unite(int u, int v) { par[find(u)] = find(v); }
} ands;
int cant[N], ind[N], sz[N], valid[1 << M], dp[6][1 << M], cur[1 << M], nxt[1 << M];
string s[N];
void transform(int n, int a[1 << M], bool inverse) {
	int till = 1 << n;
	for (int len = 1; 2 * len <= till; len <<= 1) {
		for (int i = 0; i < till; i += 2 * len) {
			for (int j = 0; j < len; j++) {
				int u = a[i + j];
				int v = a[i + len + j];

				if (!inverse) {
					a[i + j] = v;
					a[i + len + j] = u + v;
					if (a[i + len + j] >= mod) a[i + len + j] -= mod;
				} else {
					a[i + j] = (-u + v + mod);
					if (a[i + j] >= mod) a[i + j] -= mod;
					a[i + len + j] = u;
				}
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> s[j];	
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (s[i][j] == 'A')
				ands.unite(i, j);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (s[i][j] == 'X' && ands.find(i) == ands.find(j)) {
				cout << -1 << endl;
				return 0;
			}
	int m = n;
	n = 0;
	for (int i = 0; i < m; ++i) sz[ands.par[i]]++;
	for (int i = 0; i < m; ++i)
		if (ands.par[i] == i && sz[i] > 1)
			ind[i] = n++;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j) {
			int vi = ands.find(i), vj = ands.find(j);
			if (sz[vi] == 1 || sz[vj] == 1) continue;
			vi = ind[vi];
			vj = ind[vj];
			if (s[i][j] == 'X') {
				cant[vi] |= 1 << vj;
				cant[vj] |= 1 << vi;
			}
		}
	for (int mask = 0; mask < (1 << n); ++mask) {
		valid[mask ^ ((1 << n) - 1)] = 1;
		for (int v = 0; v < n; ++v)
			if (mask >> v & 1)
				if (cant[v] & mask)
					valid[mask ^ ((1 << n) - 1)] = 0;
	}
	memcpy(dp[0], valid, sizeof valid);
	transform(n, dp[0], false);
	for (int b = 0; b < 6; ++b) {
		for (int mask = 0; mask < (1 << n); ++mask) {
			if (b) dp[b][mask] = dp[b - 1][mask] * (LL) dp[b - 1][mask] % mod;
		}
	}
	cur[(1 << n) - 1] = 1;
	transform(n, cur, false);
	int res = 0;
	for (int b = 5; b >= 0; --b) {
		memcpy(nxt, cur, sizeof cur);
		for (int mask = 0; mask < (1 << n); ++mask)
			nxt[mask] = nxt[mask] * (LL) dp[b][mask] % mod;
		transform(n, nxt, true);
		if (!nxt[0]) {
			for (int mask = 0; mask < (1 << n); ++mask)
				cur[mask] = cur[mask] * (LL) dp[b][mask] % mod;
			res += (1 << b);
		}
	}
	if (n == 0) {
		--res;	
	}
	cout << m - 1 + res + 1 << '\n';

}