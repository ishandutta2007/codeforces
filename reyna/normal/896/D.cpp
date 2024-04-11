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
const int N = (int) 1e5 + 5;
int mod = 5;
vector<int> pr[N];
int pw(int a, int b) { return b != 0 ? pw((LL) a * a % mod, b >> 1) * (LL) (b & 1 ? a : 1) % mod : 1; }
struct segtree {
	int seg[N << 2], mul[N << 2];
	void build(int v = 1, int b = 1, int e = N) {
		if (b + 1 == e) {
			seg[v] = 0;
			mul[v] = 1;
			return;
		}
		int m = b + e >> 1, l = v << 1, r = l | 1;
		build(l, b, m);
		build(r, m, e);
		seg[v] = 0;
		mul[v] = mul[l] * (LL) mul[r] % mod;
	}
	
	segtree() {
		memset(seg, 0, sizeof seg);
		memset(mul, 0, sizeof mul);
//		build();
//		cout << " end " << endl;
	
	}

	void update(int pos, int x, int v = 1, int b = 1, int e = N) {
		if (b + 1 == e) {
			seg[v] += x;
			mul[v] = pw(b, max(0LL, seg[v]));
			return;
		}
		int m = b + e >> 1, l = v << 1, r = l | 1;
		if (pos < m) {
			update(pos, x, l, b, m);	
		} else {
			update(pos, x, r, m, e);
		}
		mul[v] = mul[l] * (LL) mul[r] % mod;
	}
	void add_number(int x, int t) {
		int tmp = x;
		for (int p : pr[x]) {
			int cnt = 0;
			while (tmp % p == 0) tmp /= p, ++cnt;
			update(p, cnt * t);
		}
	}
} ax, bx, cx;

int f(int n, int m) {
	ax.build();
	bx.build();
	cx.build();
//	cout << " start " << endl;
	int res = 0;
//	for (int x = 0; x <= n; ++x)
//		for (int y = x; x + y <= n; ++y) {
		//	if (y - x <= m)
		//		res = (res + (comb[x + y][x] - (x == 0 ? 0 : comb[x + y][x - 1]) + mod) % mod * comb[n][x + y] % mod) % mod;
		
	for (int xy = 0; xy <= n; ++xy)	{
			// x + y == xy
			// y - x <= m
			// y - m <= x
			// xy - x - m <= x
			// xy - m <= 2x
		int mnx = (xy - m) / 2 + (xy - m) % 2;
		int lmnx = (xy - m - 1) / 2 + (xy - m - 1) % 2;
//		cerr << " hi " << lmnx << ' ' << mnx << endl;
		mnx = max(mnx, 0LL);
		lmnx = max(lmnx, 0LL);
		if (mnx >= 2) {
			ax.add_number(xy, +1);
			ax.add_number(xy - lmnx + 1, -1);
			if (mnx != lmnx) {
				ax.add_number(xy - mnx + 2, +1);
				ax.add_number(mnx - 1, -1);
			}
		}
		int mxx = xy / 2;
		int lmxx = (xy - 1) / 2;
		if (mxx >= 1) {
			bx.add_number(xy, +1);
			bx.add_number(xy - lmxx, -1);
			if (lmxx != mxx) {
				bx.add_number(xy - mxx + 1, +1);
				bx.add_number(mxx, -1);
			}
		}
		if (xy > 0) {
			cx.add_number(n - xy + 1, +1);
			cx.add_number(xy, -1);
		}
		res = (res + (bx.mul[1] - (mnx == 0 ? 0 : ax.mul[1]) + mod) % mod * cx.mul[1] % mod) % mod;
	}
	
//		}
	return res;
}
int32_t main() {
	int n, l, r;
	cin >> n >> mod >> l >> r;
	for (int j = 2; j < N; ++j)
		if (pr[j].size() == 0)
			for (int i = j; i < N; i += j)
				pr[i].push_back(j);
//	cout << " hi " << "wtf "  << endl;
	cout << (f(n, r) - (l == 0 ? 0 : f(n, l - 1)) + mod) % mod << endl;
}