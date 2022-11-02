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

bool added[N];
ll ans;
int a[N], prev[N], rank[N], sz[N];
vi g[N];
pii p[N];

int get(int v) {
	if (prev[v] != v) {
		prev[v] = get(prev[v]);
	}
	return prev[v];
}

inline void merge(int a, int b, int c) {
	ans += 1LL * c * sz[a] * sz[b];
	if (rank[a] < rank[b]) {
		swap(a, b);
	}
	prev[b] = a;
	sz[a] += sz[b];
	if (rank[a] == rank[b]) {
		++rank[a];
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		p[i] = mp(a[i], i);
	}
	sort(p, p + n);
	reverse(p, p + n);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		g[x].pb(y);
		g[y].pb(x);
	}
	for (int i = 0; i < n; ++i) {
		prev[i] = i;
		rank[i] = 1;
		sz[i] = 1;
	}
	int i = 0;
	ans = 0;
	while (i < n) {
		int j = i;
		while (j + 1 < n && p[i].fs == p[j + 1].fs) {
			++j;
		}
		for (int z = i; z <= j; ++z) {
			int v = p[z].sc;
			added[v] = true;
		}
		for (int z = i; z <= j; ++z) {
			int v = p[z].sc;
			for (int h = 0; h < sz(g[v]); ++h) {
				if (!added[g[v][h]]) {
					continue;
				}
				int x = get(v), y = get(g[v][h]);
				if (x != y) {
					merge(x, y, p[i].fs);
				}
			}
		}
		i = j + 1;
	}
	printf("%.18lf\n", double(ans) * 2 / n / (n - 1));
	return 0;
}