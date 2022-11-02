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
const int N = 402;

int a[N][N];
int prev[N], next[N], nnext[N], nprev[N];
short last[N * N][N];
short h[N][N][N];

int main() {
	cerr << "mem = " << (sizeof(last) + sizeof(h)) / 1024 / 1024 << endl;
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < N * N; ++i) {
		for (int j = 0; j < m; ++j) {
			last[i][j] = -1;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int z = j; z >= 0; --z) {
				h[i][j][z] = max((z < j ? h[i][j][z + 1] : short(-1)), last[a[i][j]][z]);
			}
			last[a[i][j]][j] = i;
		}
	}
	for (int i = 0; i < N * N; ++i) {
		for (int j = 0; j < m; ++j) {
			last[i][j] = -1;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = m - 1; j >= 0; --j) {
			for (int z = j; z < m; ++z) {
				h[i][j][z] = max((j < z ? h[i][j][z - 1] : short(-1)), last[a[i][j]][z]);
			}
			last[a[i][j]][j] = i;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			prev[j] = -1;
			next[j] = m;
		}
		for (int j = i; j < n; ++j) {
			for (int z = 0; z < m; ++z) {
				while (prev[z] + 1 <= z && h[j][z][prev[z] + 1] >= i) {
					++prev[z];
				}
			}
			for (int z = m - 1; z >= 0; --z) {
				while (next[z] - 1 >= z && h[j][z][next[z] - 1] >= i) {
					--next[z];
				}
			}
			for (int z = 0; z < m; ++z) {
				nprev[z] = prev[z];
				nnext[z] = next[z];
			}
			for (int z = 0; z < m; ++z) {
				if (next[z] < m) {
					nprev[next[z]] = max(nprev[next[z]], z);
				}
				if (prev[z] >= 0) {
					nnext[prev[z]] = min(nnext[prev[z]], z);
				}
			}
			for (int z = 0; z < m; ++z) {
				prev[z] = nprev[z];
				next[z] = nnext[z];
			}
			int ptr = -1;
			for (int z = 0; z < m; ++z) {
				ptr = max(ptr, prev[z]);
				ans = max(ans, (j - i + 1) * (z - ptr));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}