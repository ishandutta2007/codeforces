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
const int N = (1 << 21) + 100;

ll ans[100][2];
int state[100];
int lev[N], sz[N];
int *lst[N];
int mem[N * 21];

inline ll calc(int a, int b) {
	ll res = 0, i = 0, j = 0;
	while (i < sz[a] && j < sz[b]) {
		if (lst[a][i] <= lst[b][j]) {
			++i;
		}
		else {
			res += sz[a] - i;
			++j;
		}
	}
	return res;
}

int main() {
	//cerr << sizeof(mem) / 1024 / 1024 << endl;
	int n;
	scanf("%d", &n);
	int *ptr = mem;
	for (int i = 0; i < (1 << n); ++i) {
		int cur;
		scanf("%d", &cur);
		sz[i + (1 << n)] = 1;
		lst[i + (1 << n)] = ptr++;
		lev[i + (1 << n)] = 0;
		lst[i + (1 << n)][0] = cur;
	}
	for (int i = (1 << n) - 1; i > 0; --i) {
		lev[i] = lev[i * 2] + 1;
		sz[i] = 2 * sz[i * 2];
		lst[i] = (ptr += sz[i]);
		ans[lev[i]][0] += calc(i * 2, i * 2 + 1);
		ans[lev[i]][1] += calc(i * 2 + 1, i * 2);
		int j = 0, z = 0, k = 0;
		while (j < sz[i * 2] && z < sz[i * 2]) {
			if (lst[i * 2][j] < lst[i * 2 + 1][z]) {
				lst[i][k++] = lst[i * 2][j++];
			}
			else {
				lst[i][k++] = lst[i * 2 + 1][z++];
			}
		}
		while (j < sz[i * 2]) {
			lst[i][k++] = lst[i * 2][j++];
		}
		while (z < sz[i * 2]) {
			lst[i][k++] = lst[i * 2 + 1][z++];
		}
	}
	int m;
	scanf("%d", &m);
	int mask = 0;
	for (int i = 0; i < m; ++i) {
		int q;
		scanf("%d", &q);
		mask ^= ((1 << (q + 1)) - 1);
		ll res = 0;
		for (int j = 0; j <= n; ++j) {
			res += ans[j][(mask >> j) & 1];
		}
		printf(LLD"\n", res);
	}
	return 0;
}