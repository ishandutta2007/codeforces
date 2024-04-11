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
const int N = int(1e6) + 100;

int cnt[N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n - 1 <= m && m <= 2 * (n + 1)) {
		for (int i = 1; i < n; ++i) {
			cnt[i] = 1;
			--m;
		}
		for (int i = 0; i <= n && m > 0; ++i) {
			while (cnt[i] + 1 < 3 && m > 0) {
				++cnt[i];
				--m;
			}
		}
		for (int i = 0; i <= n; ++i) {
			if (i > 0) {
				printf("0");
			}
			for (int j = 0; j < cnt[i]; ++j) {
				printf("1");
			}
		}
		puts("");
	}
	else {
		puts("-1");
	}
	return 0;
}