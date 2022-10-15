#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Maxn 101

#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

int n, m, ans, a[Maxn], f[Maxn][Maxn], pre[Maxn];
bool pos[Maxn][Maxn];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] % 2 == 0) {
			pre[i] = pre[i - 1] + 1;
		} else {
			pre[i] = pre[i - 1] - 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (pre[i - 1] == pre[j]) {
				pos[i][j] = true;
			}
		}
	}
	memset(f, 60 , sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 1; k <= n; k++) {
				if (pos[j + 1][i]) {
					if (k == 1) {
						f[k][i] = Min(f[k][i], f[k - 1][j]);
					} else {
						f[k][i] = Min(f[k][i], f[k - 1][j] + Abs(a[j] - a[j + 1]));
					}
					if (f[k][i] <= m) {
						ans = Max(ans, k - 1);
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

// By Sooke.
// CF998B Cutting.