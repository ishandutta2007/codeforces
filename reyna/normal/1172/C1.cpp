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

const int M = 1e6 + 6, N = (int) 3005, mod = (int) 998244353;
int die[N][N], alive[N][N];
int a[M], w[M], inv[M];
int pw(int a, int b) { return b == 0 ? 1 : pw((LL) a * a % mod, b >> 1) * (LL) (b & 1 ? a : 1) % mod; }
int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) cin >> a[j];
	int sum = 0;
	int sumdx = 0, sumax = 0;
	for (int j = 0; j < n; ++j) {
		cin >> w[j], sum += w[j];
		if (!a[j]) sumdx += w[j];
		else sumax += w[j];
	}
	for (int j = 0; j < 4 * m; ++j)
		inv[j] = pw(sum + j - 2 * m, mod - 2); 
	for (int s = m; s >= 0; --s) {
		for (int dx = 0; dx <= s; ++dx) {
			int ax = s - dx;
			if (sum - dx + ax < 0 || sumdx < dx) continue;
			if (s == m) {
				die[dx][ax] = 1;
				alive[dx][ax] = 1;
			} else {
				int inv_cur = inv[-dx + ax + 2 * m];//pw(sum - dx + ax, mod - 2);
				die[dx][ax] = (sumdx - dx - 1) * (LL) inv_cur % mod * die[dx + 1][ax] % mod;
				die[dx][ax] = (die[dx][ax] + (sumax + ax) * (LL) inv_cur % mod * die[dx][ax + 1]) % mod;
				alive[dx][ax] = inv_cur * (LL) alive[dx][ax + 1] * 2 % mod;
				alive[dx][ax] = (alive[dx][ax] + (sumax + ax - 1) * (LL) inv_cur % mod * alive[dx][ax + 1]) % mod;
				alive[dx][ax] = (alive[dx][ax] + (sumdx - dx) * (LL) inv_cur % mod * alive[dx + 1][ax]) % mod;
			}
		}
	}
	for (int j = 0; j < n; ++j) {
		if (!a[j]) {
			cout << die[0][0] * (LL) w[j] % mod << '\n';	
		} else {
			cout << alive[0][0] * (LL) w[j] % mod << '\n';
		}
	}
	
}