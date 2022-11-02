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

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (n == 1) {
		if (k > 0) {
			puts("-1");
			return 0;
		}
		puts("1");
		return 0;
	}
	int can = n / 2;
	if (k < can) {
		puts("-1");
		return 0;
	}
	int ptr = 1;
	for (int i = 0; i < can - 1; ++i) {
		while (ptr == k - (can - 1) || ptr + 1 == k - (can - 1) || ptr == 2 * (k - (can - 1)) || ptr + 1 == (2 * (k - (can - 1)))) {
			++ptr;
		}
		printf("%d %d ", ptr, ptr + 1);
		ptr += 2;
	}
	printf("%d %d ", k - (can - 1), 2 * (k - (can - 1)));
	if (n % 2 != 0) {
		printf("%d ", int(1e9));
	}
	puts("");
	return 0;
}