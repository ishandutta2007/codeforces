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
const int BLOCK = 300;
const int N = int(1e5) + 100;

struct point {

	ll x, y;
	
	point() {}
	
	point(ll x, ll y) {
		this->x = x;
		this->y = y;
	}
	
};

bool operator < (const point &a, const point &b) {
	return mp(a.x, a.y) < mp(b.x, b.y);
}

point operator - (const point &a, const point &b) {
	return point(a.x - b.x, a.y - b.y);
}

int k;
pii a[N];
int b[N], c[N];
int add[N / BLOCK + 10], sz[N / BLOCK + 10];
pair<ll, int> res[N / BLOCK + 10];
point p[N / BLOCK + 10][BLOCK + 10];

inline ll vec(point &a, point &b) {
	return a.x * b.y - b.x * a.y;
}

inline bool bad(point &a, point &b, point &c) {
	point v1 = b - a, v2 = c - b;
	return vec(v1, v2) >= 0;
}

inline void build(int num) {
	sz[num] = 0;
	res[num] = mp(-1LL, -1);
	for (int i = num * BLOCK; i < min((num + 1) * BLOCK, k); ++i) {
		res[num] = max(res[num], mp(1LL * b[i] * c[i], b[i]));
		p[num][sz[num]++] = point(b[i], 1LL * b[i] * c[i]);
	}
	sort(p[num], p[num] + sz[num]);
	int oldSz = sz[num];
	sz[num] = 0;
	for (int i = 0; i < oldSz; ++i) {
		while (sz[num] >= 2 && bad(p[num][sz[num] - 2], p[num][sz[num] - 1], p[num][i])) {
			--sz[num];
		}
		p[num][sz[num]++] = p[num][i];
	}
}

inline void addP(int p) {
	int pos = lower_bound(b, b + k, p) - b;
	int num = pos / BLOCK;
	for (int i = 0; i < num; ++i) {
		++add[i];
	}
	for (int i = num * BLOCK; i < min((num + 1) * BLOCK, k); ++i) {
		c[i] += add[num];
	}
	for (int i = num * BLOCK; i <= pos; ++i) {
		++c[i];
	}
	add[num] = 0;
	build(num);
}

inline pair<ll, int> get(int num) {
	if (add[num] == 0) {
		return res[num];
	}
	int ptr = sz[num] - 1, l = 0, r = sz[num] - 2;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (p[num][mid].y + p[num][mid].x * add[num] >= p[num][mid + 1].y + p[num][mid + 1].x * add[num]) {
			ptr = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	pair<ll, int> res = mp(p[num][ptr].y + p[num][ptr].x * add[num], p[num][ptr].x);
	res = max(res, mp(p[num][sz[num] - 1].y + p[num][sz[num] - 1].x * add[num], int(p[num][sz[num] - 1].x)));
	res = max(res, mp(p[num][0].y + p[num][0].x * add[num], int(p[num][0].x)));
	return res;
}

int main() {
	int n, w;
	scanf("%d %d", &n, &w);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &a[i].sc, &a[i].fs);
		b[i] = a[i].sc;
	}
	sort(a, a + n);
	sort(b, b + n);
	k = unique(b, b + n) - b;
	for (int i = 0; i * BLOCK < k; ++i) {
		build(i);
	}
	int ptr = 0;
	for (int c = 0; c <= a[n - 1].fs + 1; ++c) {
		while (ptr < n && a[ptr].fs < c) {
			addP(a[ptr++].sc);
		}
		pair<ll, int> res(0LL, b[k - 1] + 1);
		for (int j = 0; j * BLOCK < k; ++j) {
			res = max(res, get(j));
		}
		res.fs += 1LL * (n - ptr) * c * w;
		printf(LLD" %d\n", res.fs, res.sc);
	}
	return 0;
}