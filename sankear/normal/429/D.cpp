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

const ll inf = 2 * ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;

struct point {
	
	ll x, y;
	
	point() {}
	
	point(ll x, ll y) {
		this->x = x;
		this->y = y;
	}
	
};

ll ans;
point p[N], tmp[N];

inline bool cmpY(const point &a, const point &b) {
	return a.y < b.y;
}

inline bool cmpX(const point &a, const point &b) {
	return a.x < b.x;
}

inline ll sqr(ll x) {
	return x * x;
}

inline ll dist(point &a, point &b) {
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}

inline void solve(int l, int r) {
	if (r - l < 4) {
		for (int i = l; i < r; ++i) {
			for (int j = i + 1; j <= r; ++j) {
				ans = min(ans, dist(p[i], p[j]));
			}
		}
		sort(p + l, p + r + 1, cmpY);
		return;
	}
	int mid = (l + r) / 2;
	ll midX = p[mid].x;
	solve(l, mid);
	solve(mid + 1, r);
	inplace_merge(p + l, p + mid + 1, p + r + 1, cmpY);
	int sz = 0;
	for (int i = l; i <= r; ++i) {
		if (sqr(p[i].x - midX) <= ans) {
			for (int j = sz - 1; j >= 0 && sqr(p[i].y - tmp[j].y) <= ans; --j) {
				ans = min(ans, dist(p[i], tmp[j]));
			}
			tmp[sz++] = p[i];
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		int cur;
		scanf("%d", &cur);
		sum += cur;
		p[i] = point(i, sum);
	}
	sort(p, p + n, cmpX);
	ans = inf;
	solve(0, n - 1);
	printf(LLD"\n", ans);
	return 0;
}