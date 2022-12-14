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

const int N = (int) 2e5 + 5, mod = (int) 998244353;
int n, q, ch_mul[N << 2], ch_add[N << 2], sum[N << 2];
set<pair<int, int>> segs[N];

void apply(int v, int b, int e, int mulx, int addx) {
	ch_mul[v] = (LL) ch_mul[v] * mulx % mod;
	ch_add[v] = (LL) ch_add[v] * mulx % mod;
	ch_add[v] = ch_add[v] + addx;
	if (ch_add[v] >= mod)
		ch_add[v] -= mod;
	sum[v] = ((LL) sum[v] * mulx + (LL) addx * (e - b)) % mod;
}

void push(int v, int b, int e) {
	if (ch_mul[v] == 1 && ch_add[v] == 0) return;
	apply(v << 1 | 0, b, b + e >> 1, ch_mul[v], ch_add[v]);
	apply(v << 1 | 1, b + e >> 1, e, ch_mul[v], ch_add[v]);
	ch_mul[v] = 1;
	ch_add[v] = 0;
}

void update(int i, int j, int mulx, int addx, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		apply(v, b, e, mulx, addx);
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v, b, e);
	update(i, j, mulx, addx, l, b, m);
	update(i, j, mulx, addx, r, m, e);
	sum[v] = (sum[l] + sum[r]);
	if (sum[v] >= mod)
		sum[v] -= mod;
}

int query(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return 0;
	if (i <= b && e <= j) return sum[v];
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v, b, e);
	return (query(i, j, l, b, m) + query(i, j, r, m, e)) % mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			--l;
			auto it = segs[x].lower_bound(mp(l, -1));
			if (it != segs[x].begin()) {
				--it;
			}
			int full_l = l;
			int full_r = r;
			int last_r = l;
			while (it != segs[x].end() && it->first < r) {
				int xl = it->first, xr = it->second;
				if (xr <= l) {
					++it;
					continue;
				}
				int share_l = max(xl, l), share_r = min(xr, r);
				if (share_l != xl || share_r != xr) {
					full_l = min(full_l, xl);
					full_r = max(full_r, xr);
				}
				update(share_l, share_r, 2, 0);
				if (last_r < share_l) update(last_r, share_l, 1, 1);
				last_r = share_r;
				auto nx = it;
				++nx;
				segs[x].erase(it);
				it = nx;
			}
			if (last_r < r) {
				update(last_r, r, 1, 1);	
			}
			segs[x].insert(mp(full_l, full_r));
		} else {
			int l, r;
			cin >> l >> r;
			--l;
			cout << query(l, r) << '\n';
			
		}
	}
}