#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, x, ans;

int main() {
	scanf("%d %d %d %d", &a, &b, &c, &n);
	while (n --) {
		scanf("%d", &x);
		if (x > b && x < c) ans ++;
	}
	printf("%d\n", ans);
	return 0;
}