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
const int N = 19;
const int M = 100;

bool exist[10];
int lst[N];
ll d[(1 << N)][M];

int main() {
	ll n;
	int m;
	scanf(LLD" %d", &n, &m);
	int k = 0;
	while (n > 0) {
		lst[k++] = n % 10;
		n /= 10;
	}
	d[0][0] = 1;
	for (int i = 0; i < (1 << k) - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			if (d[i][j] == 0) {
				continue;
			}
			for (int z = 0; z < 10; ++z) {
				exist[z] = false;
			}
			for (int z = 0; z < k; ++z) {
				if ((i & (1 << z)) != 0) {
					continue;
				}
				if (!exist[lst[z]]) {
					if (i == 0 && lst[z] == 0) {
						// pass
					}
					else {
						int nj = (j * 10 + lst[z]) % m;
						d[(i | (1 << z))][nj] += d[i][j];
					}
				}
				exist[lst[z]] = true;
			}
		}
	}
	printf(LLD"\n", d[(1 << k) - 1][0]);
	return 0;
}