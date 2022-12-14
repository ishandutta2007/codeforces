#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
//	freopen("C.in", "r", stdin);
	LL x, y;
	scanf("%I64d %I64d", &x, &y);
	if (__gcd(x, y) > 1) return puts("Impossible"), 0;
	int t = 0;
	while (y) {
		LL r = x % y; LL d = x / y; ++t; if (y == 1) d--;
		if (d) printf("%I64d%c", d, (t & 1) ? 'A' : 'B');
		x = y; y = r;
	}
}