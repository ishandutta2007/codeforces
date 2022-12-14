#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, p;
	scanf("%d%d", &n, &p);
	int ans = 1 << 30;
	for (int i = 0; i <= 1000000; ++i)
		if (n - 1ll * p * i >= i && __builtin_popcountll(n - 1ll * p * i) <= i)
			ans = min(ans, i);
	if (ans == (1 << 30)) ans = -1;
	printf("%d\n", ans);
	return 0;
}