#include <bits/stdc++.h>
using namespace std;

int n, k, x, ans;

bool ok(int x) {
	int lucky = 0;
	while (x) {
		if (x % 10 == 4 || x % 10 == 7) lucky ++;
		x /= 10;
	}
	return lucky <= k;
}

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &k);
	while (n --) {
		scanf("%d", &x);
		if (ok(x)) ans ++;
	}
	printf("%d\n", ans);
	return 0;
}