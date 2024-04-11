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
#define int long long
const int N = (int) 40, mod = (int) 1e9 + 7;
void sadd(int &x, int y) {
	x += y;
	while (x >= mod) x -= mod;
}
int res_all = 0;
int ldp[N][8], rdp[N][8], vis[N][8];
vector<pair<pair<int, int>, int>> out[N][8], in[N][8];
int a[3];
void go(int pos, int mask = 7) {
	int cur_pos = pos;
	--pos;
	if (vis[cur_pos][mask]) return;
	vis[cur_pos][mask] = 1;
	if (cur_pos == 0) {
		return;	
	}
	for (int x = 0; x <= ((mask >> 0 & 1) ? a[0] >> pos & 1 : 1); ++x)
		for (int y = 0; y <= ((mask >> 1 & 1) ? a[1] >> pos & 1 : 1); ++y) {
			int z = x ^ y;
			if (z <= ((mask >> 2 & 1) ? a[2] >> pos & 1 : 1)) {
				int nmask = 0;
				nmask += ((mask >> 0 & 1) & ((a[0] >> pos & 1) == x)) << 0;
				nmask += ((mask >> 1 & 1) & ((a[1] >> pos & 1) == y)) << 1;
				nmask += ((mask >> 2 & 1) & ((a[2] >> pos & 1) == z)) << 2;
				
				out[cur_pos][mask].push_back(mp(mp(cur_pos - 1, nmask), z));
				in[cur_pos - 1][nmask].push_back(mp(mp(cur_pos, mask), z));
				go(cur_pos - 1, nmask);
			}
		}
}

int solve(int p, int q, int k) {
	if (p < 0) return 0;
	if (q < 0) return 0;
	a[0] = p;
	a[1] = q;
	a[2] = k;
	memset(vis, 0, sizeof vis);
	memset(ldp, 0, sizeof ldp);
	memset(rdp, 0, sizeof rdp);
	for (int j = 0; j < N; ++j) for (int i = 0; i < 8; ++i) in[j][i].clear(), out[j][i].clear();
	res_all = 0;
	go(31);
	ldp[31][7] = 1;
	for (int pos = 31; pos >= 0; --pos) {
		for (int mask = 0; mask < 8; ++mask) {
			for (auto e : in[pos][mask]) {
				int lpos = e.first.first, lmask = e.first.second;
				sadd(ldp[pos][mask], ldp[lpos][lmask]);	
			}
		}
	}
	for (int pos = 0; pos <= 31; ++pos) {
		for (int mask = 0; mask < 8; ++mask) {
			if (pos == 0) rdp[pos][mask] = 1;
			for (auto e : out[pos][mask]) {
				int rpos = e.first.first, rmask = e.first.second;
				sadd(rdp[pos][mask], rdp[rpos][rmask]);
			}
		}
	}
	res_all = 0;
	for (int pos = 0; pos <= 31; ++pos)
		for (int mask = 0; mask < 8; ++mask)
			for (auto e : out[pos][mask]) {
				int rpos = e.first.first, rmask = e.first.second, w = e.second;
				res_all = (res_all + (LL) ((LL) w << (pos - 1)) * ldp[pos][mask] % mod * rdp[rpos][rmask] % mod) % mod;
			}
	return (res_all + rdp[31][7]) % mod;
}
int32_t main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int xl, xr, yl, yr, k;
		cin >> xl >> yl >> xr >> yr >> k;
		--k;
		--xl, --yl, --xr, --yr;
		int res = solve(xr, yr, k);
		res = (res - solve(xl - 1, yr, k) + mod) % mod;
		res = (res - solve(xr, yl - 1, k) + mod) % mod;
		res = (res + solve(xl - 1, yl - 1, k)) % mod;
		cout << (res) % mod << endl;
	}
	
}