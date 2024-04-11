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
const int N = 2020;

int n, m;
char a[N][N];

inline int check(int x, int y, char ch) {
	if (x < 0 || y < 0 || x >= n || y >= m) {
		return 0;
	}
	return a[x][y] == ch;
}

inline int calc(int x, int y, int t) {
	int res = 0;
	// L
	res += check(x, y + t, 'L');
	// R
	res += check(x, y - t, 'R');
	// U
	res += check(x + t, y, 'U');
	// D
	res += check(x - t, y, 'D');
	return res;
}

int main() {
	int k;
	scanf("%d %d %d", &n, &m, &k);
	gets(a[0]);
	for (int i = 0; i < n; ++i) {
		gets(a[i]);
	}
	for (int i = 0; i < m; ++i) {
		ll ans = 0;
		for (int j = 0; j < n; ++j) {
			ans += calc(j, i, j);
		}
		printf(LLD" ", ans);
	}
	puts("");
	return 0;
}