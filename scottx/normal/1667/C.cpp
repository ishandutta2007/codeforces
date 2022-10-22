#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	int x = (n * 2 + 1) / 3;
	printf("%d\n", x);
	if (x & 1) {
		rep(i, 1, (x + 1) / 2) {
			printf("%d %d\n", i, (x + 1) / 2 + 1 - i);
		}
		rep(i, 1, x / 2) {
			printf("%d %d\n", x + 1 - i, x - x / 2 + i);
		}
	} else {
		printf("1 1\n");
		--x;
		rep(i, 1, (x + 1) / 2) {
			printf("%d %d\n", i + 1, (x + 1) / 2 + 1 - i + 1);
		}
		rep(i, 1, x / 2) {
			printf("%d %d\n", x + 1 - i + 1, x - x / 2 + i + 1);
		}
	}
}