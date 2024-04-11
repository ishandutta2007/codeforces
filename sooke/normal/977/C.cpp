#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Maxn 200005

#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

int n, m, a[Maxn];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	if (m == 0) {
		if (a[1] == 1) {
			printf("-1\n");
		} else {
			printf("%d\n", a[1] - 1);
		}
	} else {
		if (a[m] == a[m + 1]) {
			printf("-1\n");
		} else {
			printf("%d\n", a[m]);
		}
	}
	return 0;
}

// By Sooke.
// CF977C Less or Equal.