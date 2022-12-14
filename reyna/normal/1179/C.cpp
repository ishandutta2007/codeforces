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

const int N = (int) 1e6 + 6, mod = (int) 0;
int a[N], b[N], mx[N << 2], ch[N << 2];
void push(int v) {
	mx[v << 1 | 0] += ch[v];
	mx[v << 1 | 1] += ch[v];
	ch[v << 1 | 0] += ch[v];
	ch[v << 1 | 1] += ch[v];
	ch[v] = 0;
}
void update(int i, int j, int x, int v = 1, int b = 0, int e = N) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		mx[v] += x;
		ch[v] += x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	mx[v] = max(mx[l], mx[r]);
}
int query(int v = 1, int b = 0, int e = N) {
	if (mx[v] <= 0) return -1;
	if (b + 1 == e) return e;
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v);
	int ansr = query(r, m, e);
	if (ansr != -1) return ansr;
	return query(l, b, m);
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) cin >> a[j], update(0, a[j], 1);
	for (int j = 0; j < m; ++j) cin >> b[j], update(0, b[j], -1);
	int q;
	cin >> q;
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int p, x;
			cin >> p >> x;
			--p;
			update(0, a[p], -1);
			a[p] = x;
			update(0, a[p], +1);
		} else {
			int p, x;
			cin >> p >> x;
			--p;
			update(0, b[p], +1);
			b[p] = x;
			update(0, b[p], -1);
		}
		cout << query() << '\n';
	}

}