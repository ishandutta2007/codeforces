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
#define int long long
typedef long long LL;
const int N = (int) 2e5 + 5, mod = (int) 1e9 + 7;
int query(int m, int *f, int dont = 0) { ++m;
	int res = 0;
	while (m > 0) {
		res += f[m];
		m -= m & -m;
		if (dont == 0) 
			res %= mod;
	}
	return res;
}
int query(int l, int r, int *f, int dont = 0) {
	int res = query(r - 1, f, dont) - query(l - 1, f, dont);	
	if (dont == 0) {
		return (res % mod + mod) % mod;
	}
	return res;
}
void update(int m, int x, int *f, int dont = 0) { ++m;
	while (m < N) {
		f[m] = (f[m] + x);
		if (dont == 0)
			f[m] %= mod;
		m += m & -m;
	}
}

int f[N], a[N], w[N], qf[N];
int32_t main() {
	int n, q;
	cin >> n >> q;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		a[j] -= j;
	}
	for (int j = 0; j < n; ++j) {
		cin >> w[j];
		update(j, w[j], f, 1);
		update(j, (LL) a[j] * w[j] % mod, qf);
	}
	while (q--) {
		int pos, nw;
		cin >> pos >> nw;
		if (pos < 0) {
			pos = -pos;
			--pos;
			update(pos, nw - w[pos], f, 1);
			update(pos, (nw - w[pos] + mod) * (LL) a[pos] % mod, qf);
			w[pos] = nw;
		} else {
			int l = pos, r = nw;
			--l;
			int bl = l, br = r;
			int sum_all = query(l, r, f, 1);
			while (bl < br - 1) {
				int bm = bl + br >> 1;
				if (query(l, bm, f, 1) * 2 >= sum_all) {
					br = bm;
				} else {
					bl = bm;
				}
			}
			int res = (a[bl] * (LL) (query(l, bl, f, 1) % mod) - query(l, bl, qf) + mod) % mod + ((mod - a[bl]) * ((LL) query(bl, r, f, 1) % mod) + query(bl, r, qf)) % mod;
			res %= mod;
			cout << res << '\n';
		}
	}
}