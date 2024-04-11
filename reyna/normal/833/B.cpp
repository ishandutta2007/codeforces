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

const int N = (int) 1e5 + 5, mod = (int) 0;
int n, k, a[N], dp[N], seg[N << 2], ch[N << 2];
void build(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		seg[v] = dp[b];
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	seg[v] = max(seg[l], seg[r]);
}
void update(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		seg[v] += x;
		ch[v] += x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	seg[v] = max(seg[l], seg[r]) + ch[v];
}
int query(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return -1e9;
	if (i <= b && e <= j) return seg[v];
	int m = b + e >> 1, l = v << 1, r = l | 1;
	return max(query(i, j, l, b, m), query(i, j, r, m, e)) + ch[v];
}
int last[N];
int main() {
	cin >> n >> k;
	for (int j = 0; j < n; ++j)
		cin >> a[j];
	memset(dp, -63, sizeof dp);
	dp[0] = 0;
	for (int pick = 0; pick < k; ++pick) {
		memset(ch, 0, sizeof ch);
		memset(seg, -63, sizeof seg);
		build();	
		memset(last, -1, sizeof last);
		for (int j = 0; j <= n; ++j) {
			dp[j] = query(0, j);
			int x = a[j];
			if (last[x] != -1) {
				update(0, last[x] + 1, -1);
			}
			update(0, j + 1, +1);
			last[a[j]] = j;	
		}
	}
	cout << dp[n] << endl;
}