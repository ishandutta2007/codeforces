#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Maxn 11

#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

int n, m, tot, a[Maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		tot += a[i];
	}
	if (n == 1) {
		printf("-1\n");
	} else if (n == 2) {
		if (a[1] == a[2]) {
			printf("-1\n");
		} else {
			printf("1\n%d\n", 1);
		}
	} else {
		int sum = 0, ans = 0;
		for (int i = 1; i < n; i++) {
			sum += a[i];
			tot -= a[i];
			if (sum != tot) {
				ans = i;
				break;
			}
		}
		if (ans == 0) {
			printf("-1");
		} else {
			printf("%d\n", ans);
			for (int i = 1; i <= ans; i++) {
				printf("%d ", i);
			}
		}
	}
	return 0;
}

// By Sooke.
// CF998A Balloons.