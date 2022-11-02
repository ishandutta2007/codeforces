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

bool used[N];
int init[N], goal[N];
vi g[N];
vi ans;

void dfs(int v, int col, int iadd[2]) {
	used[v] = true;
	int add[2];
	add[0] = iadd[0];
	add[1] = iadd[1];
	if (init[v] ^ add[col] != goal[v]) {
		ans.pb(v);
		add[col] ^= 1;
	}
	for (int i = 0; i < sz(g[v]); ++i) {
		if (!used[g[v][i]]) {
			dfs(g[v][i], col ^ 1, add);
		}
	}	
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &init[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &goal[i]);
	}
	int add[2];
	add[0] = add[1] = 0;
	dfs(0, 0, add);
	printf("%d\n", sz(ans));
	for (int i = 0; i < sz(ans); ++i) {
		printf("%d\n", ans[i] + 1);
	}
	return 0;
}