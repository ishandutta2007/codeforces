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

const int N = (int) 2e5 + 5, mod = (int) 0;
set<int> xl[N];
set<int, greater<int>> xr[N];
int a[N], n, cnt_num, mn[N << 2], cnt[N << 2], ch[N << 2];
void build(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		mn[v] = 0;
		cnt[v] = 1;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	mn[v] = min(mn[l], mn[r]);
	cnt[v] = (mn[v] == mn[l] ? cnt[l] : 0) + (mn[v] == mn[r] ? cnt[r] : 0);
}
void push(int v) {
	mn[v << 1 | 0] += ch[v];
	mn[v << 1 | 1] += ch[v];
	ch[v << 1 | 0] += ch[v];
	ch[v << 1 | 1] += ch[v];
	ch[v] = 0;
}
void update(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		mn[v] += x;
		ch[v] += x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	mn[v] = min(mn[l], mn[r]);
	cnt[v] = (mn[v] == mn[l] ? cnt[l] : 0) + (mn[v] == mn[r] ? cnt[r] : 0);
}
/*
pair<int, int> query(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return mp(1, 0);
	if (i <= b && e <= j) return mp(mn[v], cnt[v]);
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	auto ansl = query(i, j, l, b, m);
	auto ansr = query(i, j, r, m, e);
	int ansmn = min(ansl.first, ansr.first);
	int anscnt = (ansmn == ansl.first ? ansl.second : 0) + (ansmn == ansr.first ? ansr.second : 0);
	return mp(ansmn, anscnt);
}
*/
void add_int(int x, int p) {
	if (!xl[x].size() || !xr[x].size()) return;	
	int l = *(xl[x].begin()), r = *(xr[x].begin());
	update(l, r, p);
}
void add_num(int x, int pos) {
//	add_int(x, -1);
	cnt_num -= (xl[x].size() != 0);
	xl[x].insert(pos);
	xr[x].insert(pos);
	cnt_num += (xl[x].size() != 0);
//	add_int(x, +1);
}
void del_num(int x, int pos) {
//	add_int(x, -1);
	cnt_num -= (xl[x].size() != 0);
	xl[x].erase(pos);
	xr[x].erase(pos);
	cnt_num += (xl[x].size() != 0);
//	add_int(x, +1);
}
int get_ans() {
	int blocks = (mn[1] != 0 ? 1 : cnt[1] + 1);
	return cnt_num - blocks;
}
int rmost[N], lmost[N], o[N];
int cmp(int x, int y) {
	return lmost[x] < lmost[y];	
}
int main() {
	int q;
	cin >> n >> q;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int j = 0; j < n; ++j) {
		rmost[a[j]] = j;
		cnt[a[j]]++;
	}
	for (int j = n - 1; j >= 0; --j) lmost[a[j]] = j;
	int m = 0;
	for (int j = 0; j < n; ++j) {
		if (j == lmost[a[j]]) {
			o[m++] = a[j];	
		}
	}
	sort(o, o + m, cmp);
	int res = n;
	int mx = 0;
	int r = -1;
	for (int i = 0; i < m; ++i) {
		int j = o[i];
		if (lmost[j] < r) {
			mx = max(mx, cnt[j]);
			r = max(r, rmost[j]);
		} else {
			res -= mx;
			mx = cnt[j];
			r = rmost[j];
		}
	}
	res -= mx;
	cout << res << endl;
	
}