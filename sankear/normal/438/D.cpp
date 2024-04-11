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

int n, maxv;
int a[N];
ll f[N];
pii rmq[4 * N];

inline void update(int pos, int val) {
	int delta = val - a[pos];
	a[pos] = val;
	int v = pos + maxv;
	rmq[v] = mp(a[pos], pos);
	while (v > 1) {
		v /= 2;
		rmq[v] = max(rmq[v * 2], rmq[v * 2 + 1]);
	}
	while (pos < n) {
		f[pos] += delta;
		pos = (pos | (pos + 1));
	}
}

inline pii get(int l, int r) {
	pii res(-inf, -1);
	l += maxv;
	r += maxv;
	while (l <= r) {
		res = max(res, rmq[l]);
		l = (l + 1) / 2;
		res = max(res, rmq[r]);
		r = (r - 1) / 2;
	}
	return res;
}

inline ll get(int pos) {
	ll res = 0;
	while (pos >= 0) {
		res += f[pos];
		pos = (pos & (pos + 1)) - 1;
	}
	return res;
}

int main() {
	int m;
	scanf("%d %d", &n, &m);
	maxv = 1;
	while (maxv < n) {
		maxv *= 2;
	}
	for (int i = 0; i < n; ++i) {
		int cur;
		scanf("%d", &cur);
		a[i] = cur;
		rmq[i + maxv] = mp(cur, i);
		f[i] += cur;
		if ((i | (i + 1)) < n) {
			f[(i | (i + 1))] += f[i];
		}
	}
	for (int i = n; i < maxv; ++i) {
		rmq[i + maxv] = mp(-inf, -1);
	}
	for (int i = maxv - 1; i > 0; --i) {
		rmq[i] = max(rmq[i * 2], rmq[i * 2 + 1]);
	}
	for (int i = 0; i < m; ++i) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int l, r;
			scanf("%d %d", &l, &r);
			--l;
			--r;
			ll res = get(r) - (l > 0 ? get(l - 1) : 0);
			printf(LLD"\n", res);
			continue;
		}
		if (t == 2) {
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			--l;
			--r;
			pii cur = get(l, r);
			while (cur.fs >= x) {
				update(cur.sc, cur.fs % x);
				cur = get(l, r);
			}
			continue;
		}
		int k, x;
		scanf("%d %d", &k, &x);
		--k;
		update(k, x);
	}
	return 0;
}