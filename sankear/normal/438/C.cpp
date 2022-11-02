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
const int N = 222;
const int MOD = int(1e9) + 7;

struct point {
	
	ll x, y;
	
	point() {}
	
	point(ll x, ll y) {
		this->x = x;
		this->y = y;
	}
	
};

bool operator == (const point &a, const point &b) {
	return a.x == b.x && a.y == b.y;
}

bool operator < (const point &a, const point &b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	return a.y < b.y;
}

point operator - (const point &a, const point &b) {
	return point(a.x - b.x, a.y - b.y);
}

int n;
bool can[N][N], used[N][N];
ll d[N][N];
point p[N];

inline ll vec(const point &a, const point &b) {
	return a.x * b.y - b.x * a.y;
}

inline bool inSeg(point &a, point &b, point &c) {
	int minX = a.x, maxX = b.x;
	if (minX > maxX) {
		swap(minX, maxX);
	}
	int minY = a.y, maxY = a.y;
	if (minY > maxY) {
		swap(minY, maxY);
	}
	return vec(b - a, c - a) == 0 && minX <= c.x && c.x <= maxX && minY <= c.y && c.y <= maxY;
}

inline int sgn(ll val) {
	if (val == 0) {
		return 0;
	}
	if (val < 0) {
		return -1;
	}
	return 1;
}

inline bool inter(point &a, point &b, point &c, point &d) {
	if (inSeg(a, b, c) || inSeg(a, b, d) || inSeg(c, d, a) || inSeg(c, d, b)) {
		return true;
	}
	return sgn(vec(b - a, c - a)) != sgn(vec(b - a, d - a)) && sgn(vec(d - c, a - c)) != sgn(vec(d - c, b - c));
}

int calc(int l, int r) {
	if (used[l][r]) {
		return d[l][r];
	}
	used[l][r] = true;
	int cp = (l + 1) % n;
	if (cp == r) {
		return d[l][r] = 1;
	}
	d[l][r] = 0;
	while (cp != r) {
		if (can[l][cp] && can[r][cp] && vec(p[cp] - p[l], p[r] - p[l]) > 0) {
			d[l][r] = (d[l][r] + 1LL * calc(l, cp) * calc(cp, r)) % MOD;
		}
		cp = (cp + 1) % n;
	}
	return d[l][r];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(LLD" "LLD, &p[i].x, &p[i].y);
	}
	ll sq = 0;
	for (int i = 0; i < n; ++i) {
		sq += vec(p[i], p[(i + 1) % n]);
	}
	if (sq < 0) {
		reverse(p, p + n);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			can[i][j] = true;
			for (int z = 0; z < n; ++z) {
				int nz = (z + 1) % n;
				if (z == i || nz == i || z == j || nz == j) {
					continue;
				}
				if (inter(p[i], p[j], p[z], p[(z + 1) % n])) {
					can[i][j] = false;
					break;
				}
			}
		}
	}
	printf("%d\n", calc(0, n - 1));
	return 0;
}