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

int p;
int lst[N];

inline ll sqr(ll x) {
	return x * x;
}

inline int calc(int n, int m) {
	int k = n / m;
	int res = ((1LL * k * (k + 1)) / 2) % p;
	res = (1LL * res * m) % p;
	return res;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int L, R;
	scanf("%d %d", &L, &R);
	scanf("%d", &p);
	int ans = 0;
	// prepare (0, 1)
	if (L == 1) {
		ans = (ans + 1LL * (n + 1) * m) % p;
	}
	// prepare (1, 0)
	if (L == 1) {
		ans = (ans + 1LL * (m + 1) * n) % p;
	}
	for (int x = 1; x <= n; ++x) {
		int y1 = -1, l = 1, r = m;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (sqr(x) + sqr(mid) >= sqr(L)) {
				y1 = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		if (y1 == -1) {
			continue;
		}
		int y2 = -1;
		l = 1, r = m;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (sqr(x) + sqr(mid) <= sqr(R)) {
				y2 = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		if (y2 == -1 || y1 > y2) {
			continue;
		}
		int cur = x, sz = 0;
		for (int j = 2; j * j <= cur; ++j) {
			if (cur % j == 0) {
				lst[sz++] = j;
				while (cur % j == 0) {
					cur /= j;
				}
			}
		}
		if (cur > 1) {
			lst[sz++] = cur;
		}
		int resCnt = 0, resSum = 0;
		for (int j = 1; j < (1 << sz); ++j) {
			int ones = 0, cur = 1;
			for (int z = 0; z < sz; ++z) {
				if ((j & (1 << z)) != 0) {
					++ones;
					cur *= lst[z];
				}
			}
			int cnt = y2 / cur - (y1 - 1) / cur;
			int sum = (calc(y2, cur) - calc(y1 - 1, cur) + p) % p;
			if (ones % 2 != 0) {
				resCnt += cnt;
				resSum = (resSum + sum) % p;
			}
			else {
				resCnt -= cnt;
				resSum = (resSum - sum + p) % p;
			}
		}
		resCnt = (y2 - y1 + 1) - resCnt;
		resSum = ((calc(y2, 1) - calc(y1 - 1, 1) + p) % p - resSum + p) % p;
		int addCnt = (1LL * (n - x + 1) * (m + 1)) % p;
		addCnt = (1LL * addCnt * resCnt) % p;
		int addSum = (1LL * (n - x + 1) * resSum) % p;
		int res = (addCnt - addSum + p) % p;
		res = (2LL * res) % p;
		ans = (ans + res) % p;
	}
	printf("%d\n", ans);
	return 0;
}