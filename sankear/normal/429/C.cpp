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
const int N = 30;

double start;
int n, it = 0;
int a[N], bal[N], ost[N], suff[N];

void gen(int x, int y) {
	++it;
	if (it >= 100) {
		if (clock() - start > 0.9 * CLOCKS_PER_SEC) {
			puts("NO");
			exit(0);
		}
		it = 0;
	}
	if (y + suff[x] > n - x) {
		return;
	}
	if (x >= n) {
		for (int i = 0; i < n; ++i) {
			if (ost[i] != 1) {
				return;
			}
		}
		puts("YES");
		exit(0);
	}
	ost[x] = a[x];
	bal[x] = 0;
	if (a[x] > 1) {
		y += 2;
		bal[x] = 2;
	}
	if (x == 0) {
		gen(x + 1, y);
		return;
	}
	for (int i = 0; i < x; ++i) {
		if (ost[i] > 1 && ost[i] - a[x] >= 1) {
			ost[i] -= a[x];
			bool need = false;
			if (bal[i] > 0) {
				need = true;
				--bal[i];
				--y;
			}
			if (!(ost[i] == 1 && bal[i] > 0)) {
				gen(x + 1, y);
			}
			if (need) {
				++bal[i];
				++y;
			}
			ost[i] += a[x];
		}
	}
}

int main() {
	start = clock();
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = n - 1; i >= 0; --i) {
		suff[i] = suff[i + 1] + (a[i] > 1 ? 2 : 0);
	}
	gen(0, 0);
	puts("NO");
	return 0;
}