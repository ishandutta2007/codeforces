#include <bits/stdc++.h>

using namespace std;

long long n, m, ans, l, r, mid;

int main() {
	scanf("%I64d%I64d", &n, &m);
	if (n <= m) ans = n;
	else {
		l = 1, r = 1ll << 31;
		while (l < r) {
			mid = l + r >> 1;
			if (mid * (mid + 1) / 2  >= n - m) r = mid;
			else l = mid + 1;
		} 
		ans = l + m;
	}
	printf("%I64d", ans);
	return 0; 
}