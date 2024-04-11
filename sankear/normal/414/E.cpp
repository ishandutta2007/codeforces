#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define len(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define hash _hash
#define y0 yy0
#define y1 yy1
#define link _link

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;

struct node {
	
	int ver, val, minVal, maxVal, add;
	int h, sz, p, l, r;
	
	node() {
		minVal = inf;
		maxVal = -inf;
		sz = 0;
	}
	
	node(int ver, int val) {
		this->ver = ver;
		this->val = minVal = maxVal = val;
		add = 0;
		h = (rand() << 16) | rand();
		sz = 1;
		p = l = r = 0;
	}
	
};

int sz, root;
int first[N], last[N];
vi sons[N];
node d[5 * N];

inline void push(int v) {
	if (v == 0 || d[v].add == 0) {
		return;
	}
	d[v].val += d[v].add;
	d[v].minVal += d[v].add;
	d[v].maxVal += d[v].add;
	if (d[v].l > 0) {
		d[d[v].l].add += d[v].add;
	}
	if (d[v].r > 0) {
		d[d[v].r].add += d[v].add;
	}
	d[v].add = 0;
}	

inline void calc(int v) {
	push(v);
	push(d[v].l);
	push(d[v].r);
	d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
	d[v].minVal = min(d[v].val, min(d[d[v].l].minVal, d[d[v].r].minVal));
	d[v].maxVal = max(d[v].val, max(d[d[v].l].maxVal, d[d[v].r].maxVal));
	d[v].p = 0;
	if (d[v].l > 0) {
		d[d[v].l].p = v;
	}
	if (d[v].r > 0) {
		d[d[v].r].p = v;
	}
}

int merge(int l, int r) {
	push(l);
	push(r);
	if (l == 0) {
		return r;
	}
	if (r == 0) {
		return l;
	}
	int res;
	if (d[l].h > d[r].h) {
		d[l].r = merge(d[l].r, r);
		res = l;
	}
	else {
		d[r].l = merge(l, d[r].l);
		res = r;
	}
	calc(res);
	return res;
}

void dfs(int v, int ch = 0) {
	d[++sz] = node(v, ch);
	root = merge(root, sz);
	first[v] = sz;
	for (int i = 0; i < sz(sons[v]); ++i) {
		dfs(sons[v][i], ch + 1);
		d[++sz] = node(v, ch);
		root = merge(root, sz);
	}
	d[++sz] = node(v, ch);
	root = merge(root, sz);
	last[v] = sz;
}

inline int getNum(int v) {
	int res = d[d[v].l].sz + 1;
	while (d[v].p > 0) {
		int pv = d[v].p;
		if (d[pv].r == v) {
			res += d[d[pv].l].sz + 1;
		}
		v = pv;
	}
	return res;
}

inline int getPos(int v) {
	return getNum(first[v]);
}

inline int getVal(int v, int num) {
	push(v);
	if (d[d[v].l].sz + 1 == num) {
		return d[v].val;
	}
	if (d[d[v].l].sz + 1 > num) {
		return getVal(d[v].l, num);
	}
	else {
		return getVal(d[v].r, num - d[d[v].l].sz - 1);
	}
}

inline int getVal(int v) {
	return getVal(root, getNum(first[v]));
}

void splitSize(int v, int sz, int &l, int &r) {
	push(v);
	if (v == 0) {
		l = r = 0;
		return;
	}
	if (d[d[v].l].sz + 1 <= sz) {
		splitSize(d[v].r, sz - d[d[v].l].sz - 1, d[v].r, r);
		l = v;
	}
	else {
		splitSize(d[v].l, sz, l, d[v].l);
		r = v;
	}
	calc(v);
}

inline int getDist(int v, int u) {
	int l = getPos(v), r = getPos(u);
	if (l > r) {
		swap(l, r);
	}
	int p1, p2, p3;
	splitSize(root, r, p1, p3);
	splitSize(p1, l - 1, p1, p2);
	int res = d[p2].minVal;
	root = merge(p1, merge(p2, p3));
	return getVal(v) + getVal(u) - 2 * res;
}

inline int findKth(int v, int k) {
	push(v);
	if (v == 0) {
		return -1;
	}
	if (d[v].val == k) {
		int res = findKth(d[v].r, k);
		if (res == -1) {
			res = d[v].ver;
		}
		return res;
	}
	push(d[v].r);
	if (d[v].r > 0 && d[d[v].r].minVal <= k && d[d[v].r].maxVal >= k) {
		return findKth(d[v].r, k);
	}
	return findKth(d[v].l, k);
}

void write(int v) {
	push(v);
	if (v == 0) {
		return;
	}
	write(d[v].l);
	cerr << "(" << d[v].ver << ", " << d[v].val << ") ";
	write(d[v].r);
}

inline void move(int v, int k) {
	int h = getVal(v);
	int p1, p2, p3;
	splitSize(root, getPos(v) - 1, p1, p2);
	int pv = findKth(p1, h - k);
	splitSize(p2, getNum(last[v]), p2, p3);
	d[p2].add -= (k - 1);
	push(p2);
	root = merge(p1, p3);
	splitSize(root, getNum(last[pv]) - 1, p1, p3);
	d[++sz] = node(pv, h - k);
	p2 = merge(p2, sz);
	root = merge(p1, merge(p2, p3));
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int sz;
		scanf("%d", &sz);
		for (int j = 0; j < sz; ++j) {
			int cur;
			scanf("%d", &cur);
			--cur;
			sons[i].pb(cur);
		}
	}
	sz = root = 0;
	dfs(0);
	for (int i = 0; i < m; ++i) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int v, u;
			scanf("%d %d", &v, &u);
			--v;
			--u;
			printf("%d\n", getDist(v, u));
			continue;
		}
		if (t == 2) {
			int v, h;
			scanf("%d %d", &v, &h);
			--v;
			move(v, h);
			continue;
		}
		int k;
		scanf("%d", &k);
		printf("%d\n", findKth(root, k) + 1);
	}
	return 0;
}