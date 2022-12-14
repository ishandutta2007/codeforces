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

const int N = (int) 2005, mod = (int) 998244353;
int pw(int a, int b) { return b == 0 ? 1 : (LL) pw((LL) a * a % mod, b >> 1) * (b & 1 ? a : 1) % mod; }
int prob[N][N], p[N], inv[N], dp[N], intact[N];
void sadd(int &x, int y) {
	x += y;
	while (x >= mod) x -= mod;
	while (x < 0   ) x += mod;
}
int main() {
	int n, pa, pb;
	cin >> n >> pa >> pb;
	p[0] = inv[0] = 1;
	p[1] = pa * (LL) pw(pb, mod - 2) % mod;
	inv[1] = (1 - p[1] + mod) % mod;
	for (int j = 2; j < N; ++j) p[j] = pw(p[1], j), inv[j] = pw(inv[1], j);
	prob[0][0] = 1;
	for (int sum = 0; sum <= n; ++sum) {
		for (int xl = 0; xl <= sum; ++xl) {
			int xr = sum - xl;
			sadd(prob[xl + 1][xr], inv[xr] * (LL) prob[xl][xr] % mod);
			sadd(prob[xl][xr + 1], p[xl] * (LL) prob[xl][xr] % mod);
		}
	}
	intact[0] = intact[1] = 1;
	for (int sz = 2; sz <= n; ++sz) {
		int all = 0;
		for (int xr = 1; xr <= sz - 1; ++xr) {
			int xl = sz - xr;
			sadd(all, intact[xr] * (LL) prob[xl][xr] % mod);
		}
		intact[sz] = (1 - all + mod) % mod;	
		int denum = pw(all, mod - 2);
		for (int xr = 1; xr <= sz - 1; ++xr) {
			int xl = sz - xr;
			int edges = (dp[xl] - (xl * (xl - 1) / 2) + mod) % mod + (dp[xr] + mod) % mod;
			edges %= mod;
			sadd(dp[sz], edges * (LL) intact[xr] % mod * prob[xl][xr] % mod * denum % mod);
		}
		int happen = sz * (sz - 1) / 2 * (LL) pw((1 - intact[sz] + mod) % mod, mod - 2) % mod;
		sadd(dp[sz], happen);
	}
	cout << dp[n];
}