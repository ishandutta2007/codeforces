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
const int MOD = int(1e9) + 7;
const int N = 2020;

int d[N][N];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		d[1][i] = 1;
	}
	for (int i = 1; i < k; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] == 0) {
				continue;
			}
			for (int z = j; z <= n; z += j) {
				d[i + 1][z] += d[i][j];
				if (d[i + 1][z] >= MOD) {
					d[i + 1][z] -= MOD;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += d[k][i];
		if (ans >= MOD) {
			ans -= MOD;
		}
	}
	printf("%d\n", ans);
	return 0;
}