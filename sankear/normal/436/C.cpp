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
const int N = 12;
const int K = 1010;

struct te {
	
	int a, b, c;
	
};

bool operator < (const te &a, const te &b) {
	return a.c < b.c;
}

int n, m, w;
bool used[K];
char a[K][N][N];
vi g[K];
int prev[K], rank[K];
te e[K * K];

inline int calc(int p1, int p2) {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cnt += (a[p1][i][j] != a[p2][i][j]);
		}
	}
	return cnt * (p1 == 0 ? 1 : w);
}

int get(int a) {
	if (prev[a] != a) {
		prev[a] = get(prev[a]);
	}
	return prev[a];
}

inline void merge(int a, int b) {
	if (rank[a] < rank[b]) {
		swap(a, b);
	}
	prev[b] = a;
	if (rank[a] == rank[b]) {
		++rank[a];
	}
}

void dfs(int v, int pv) {
	used[v] = true;
	if (v > 0) {
		printf("%d %d\n", v, pv);
	}
	for (int i = 0; i < sz(g[v]); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i], v);
		}
	}
}

int main() {
	int k;
	scanf("%d %d %d %d", &n, &m, &k, &w);
	gets(a[0][0]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[0][i][j] = '?';
		}
	}
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < n; ++j) {
			gets(a[i][j]);
		}
	}
	int sz = 0;
	for (int i = 0; i < k; ++i) {
		for (int j = i + 1; j <= k; ++j) {
			e[sz].a = i;
			e[sz].b = j;
			e[sz++].c = calc(i, j);
		}
	}
	sort(e, e + sz);
	for (int i = 0; i <= k; ++i) {
		prev[i] = i;
		rank[i] = 1;
	}
	ll ans = 0;
	for (int i = 0; i < sz; ++i) {
		int a = get(e[i].a), b = get(e[i].b);
		if (a != b) {
			ans += e[i].c;
			g[e[i].a].pb(e[i].b);
			g[e[i].b].pb(e[i].a);
			merge(a, b);
		}
	}
	printf(LLD"\n", ans);
	dfs(0, -1);
	return 0;
}