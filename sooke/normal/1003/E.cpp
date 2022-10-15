#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Inf 2147483647
#define Maxn 400005
#define Maxe 800005

#define Swap(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

struct List {
	int len, fst[Maxn], nxt[Maxe], v[Maxe];
	inline void init(int d) {
		for (int i = 1; i <= d; i++) {
			fst[i] = -1;
		}
		len = 0;
	}
	inline void insert(int _u, int _v) {
		v[len] = _v;
		nxt[len] = fst[_u];
		fst[_u] = len++;
	}
};

List L;
int n, m, k, p, deg[Maxn];

void dfs(int u, int d) {
	if (d == 0) {
		return;
	}
	while (deg[u] > 0 && p < n) {
		p++;
		deg[u]--;
		deg[p] = k - 1;
		L.insert(u, p);
		dfs(p, d - 1);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	if (m >= n || n == 1) {
		printf("NO\n");
		return 0;
	}
	if (n == 2) {
		printf("YES\n");
		printf("1 2\n");
		return 0;
	}
	if (k == 1 || m >= n) {
		printf("NO\n");
		return 0;
	}
	L.init(n);
	for (int i = 2; i <= m + 1; i++) {
		L.insert(i - 1, i);
	}
	p = m + 1;
	for (int i = 1; i <= m + 1; i++) {
		int eng = Min(i - 1, m + 1 - i);
		deg[i] = k - 2;
		dfs(i, eng);
	}
	if (p < n) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++) {
		for (int j = L.fst[i]; j != -1; j = L.nxt[j]) {
			printf("%d %d\n", i, L.v[j]);
		}
	}
	return 0;
}

// By Sooke.
// CF1003E Tree Constructing.