#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200000 + 10;
int t, n;

int main() {
	scanf("%d", &t);
	while (t --) {
		int c[2] = {0};
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			int x; scanf("%d", &x); c[x] ++;
		}


		if (c[1] > c[0]) {
			int x = c[1]; if (x % 2 == 1) -- x;
			printf("%d\n", x);
			for (int i = 1; i <= x; i ++) printf("1 ");
		} else {
			printf("%d\n", c[0]);
			for (int i = 1; i <= c[0]; i ++) printf("0 ");
		}
		printf("\n");
	}
}