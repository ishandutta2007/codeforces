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
#include <stack>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define fs first
#define sc second

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9) + 100;
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;

struct mystack {

	int k;
	pii st[N];
	int prev[N], val[N], rank[N];

	mystack() {
		k = 1;
		st[0] = mp(inf, -1);
	}

	int get(int v) {
		int u = v;
		while (prev[v] != v) {
			v = prev[v];
		}
		while (u != v) {
			int w = prev[u];
			prev[u] = v;
			u = w;
		}
		return v;
	}

	void merge(int a, int b, int c) {
		if (rank[a] < rank[b]) {
			swap(a, b);
		}
		prev[b] = a;
		if (rank[a] == rank[b]) {
			++rank[a];
		}
		val[a] = c;
	}

	void add(pii cval) {
		prev[cval.sc] = cval.sc;
		rank[cval.sc] = 1;
		val[cval.sc] = cval.fs;
		while (k > 0 && st[k - 1].fs <= cval.fs) {
			merge(get(st[--k].sc), get(cval.sc), cval.fs);
		}
		st[k++] = cval;
	}

	int get_val(int pos) {
		return val[get(pos)];
	}

};

int maxv;
int rsq[4 * N];
int d[N];
mystack s_min, s_max;

inline void update(int pos, int val) {
	pos += maxv;
	rsq[pos] = val;
	while (pos > 1) {
		pos /= 2;
		rsq[pos] = min(rsq[pos * 2], rsq[pos * 2 + 1]);
	}
}

inline int get_min(int l, int r) {
	int res = inf;
	l += maxv;
	r += maxv;
	while (l <= r) {
		res = min(res, rsq[l]);
		l = (l + 1) / 2;
		res = min(res, rsq[r]);
		r = (r - 1) / 2;
	}
	return res;
}

int main() {
#ifdef LOCAL42
#define TASK "B"
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
#else

#endif
	int n, s, L;
	scanf("%d %d %d", &n, &s, &L);
	maxv = 1;
	while (maxv < n + 1) {
		maxv *= 2;
	}
	for (int i = 1; i < 2 * maxv; ++i) {
		rsq[i] = inf;
	}
	update(0, 0);
	for (int i = 1; i <= n; ++i) {
		int cur;
		scanf("%d", &cur);
		d[i] = inf;
		s_max.add(mp(cur, i));
		s_min.add(mp(-cur, i));
		int gl = i + 1, l = 1, r = i - L + 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (s_max.get_val(mid) + s_min.get_val(mid) <= s) {
				gl = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		int gr = -1;
		l = gl;
		r = i - L + 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (s_max.get_val(mid) + s_min.get_val(mid) <= s) {
				gr = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		d[i] = min(d[i], get_min(gl - 1, gr - 1) + 1);
		update(i, d[i]);
	}
	if (d[n] == inf) {
		puts("-1");
	} else {
		printf("%d\n", d[n]);
	}
	return 0;
}