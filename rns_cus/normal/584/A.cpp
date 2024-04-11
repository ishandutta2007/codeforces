#include <bits/stdc++.h>
using namespace std;

int n, t, r;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &t);
	if (n == 1) {
		printf("%d\n", t < 10 ? t : -1); return 0;
	}
	for (int i = 1; i < n; i ++) printf("1"), r = (r * 10 + 1) % t;
	printf("%d\n", (t - r * 10 % t) % t);
	return 0;
}