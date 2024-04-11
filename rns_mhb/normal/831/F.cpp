#include <bits/stdc++.h>
using namespace std;

#define N 110

int n;
long long k, ans, a[N];

bool test(long long x) {
	long long y = 0;
	for (int i = 1; i <= n; i ++) y += (a[i] + x - 1) / x;
	return x * y <= k; 
}

int main() {
	scanf("%d%I64d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%I64d", &a[i]);
		k += a[i];
	}
	for (int i = 1; i <= sqrt(k); i ++) {
		if (test(i)) ans = max(ans, 1ll * i);
		if (test(k / i)) ans = max(ans, k / i);
	}
	printf("%I64d", ans);
}