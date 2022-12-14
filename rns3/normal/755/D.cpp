#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	long long now = 1ll;
	scanf("%d %d", &n, &k);
	if (k > n / 2) k = n - k;
	for (int i = 1; i <= n; i ++) {
		now += (1ll * i * k) / n + 1ll + ((i - 1ll) * k) / n;
		if (i == n) printf("%I64d\n", now - 1ll);
		else printf("%I64d ", now);
	}
	return 0;
}