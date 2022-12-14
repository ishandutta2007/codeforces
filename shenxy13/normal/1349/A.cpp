#include <cstdio>
#include <algorithm>
using namespace std;
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int n;
	scanf("%d", &n);
	long long a[n], prv = 1, ths = 1, ans = 0;
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	prv = ths = a[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		ths = gcd(ths, a[i]);
		ans = gcd(ans, a[i] * prv / ths);
		prv = ths;
	}
	printf("%lld", ans);
	return 0;
}