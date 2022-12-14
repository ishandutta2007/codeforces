#include <bits/stdc++.h>

using namespace std;

long long n, m, ans;
int main() {
	scanf("%lld", &n);
	m = n * n;
	if (n == 0) return puts("1"), 0;
	if (n == 1) return puts("4"), 0;
	for (long long x = 0, y = n; x < n && x <= y; x ++) {
		while (x * x + y * y > m) y --;
		if (x > y) break;
		if (x != y) ans += 2; else ans ++;
	}
	printf("%lld\n", (ans - 2) * 4 + 4);
	return 0;
}