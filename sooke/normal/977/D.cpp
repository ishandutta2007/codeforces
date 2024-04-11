#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Maxn 105

#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

int n, b;
long long a[Maxn];
bool fe[Maxn][Maxn], be[Maxn][Maxn];

void dfs1(int u) {
	for (int i = 1; i <= n; i++) {
		if (be[u][i]) {
			dfs1(i);
			return;
		}
	}
	b = u;
}
void dfs2(int u) {
	printf("%I64d ", a[u]);
	for (int i = 1; i <= n; i++) {
		if (fe[u][i]) {
			dfs2(i);
			return;
		}
	}
} 

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j && (a[i] * 2 == a[j] || a[j] * 3 == a[i])) {
				fe[i][j] = true;
				be[j][i] = true;
			}
		}
	}
	dfs1(1);
	dfs2(b);
	return 0;
}

// By Sooke.
// CF977D Divide by three, multiply by two.