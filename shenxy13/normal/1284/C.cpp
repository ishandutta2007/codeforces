#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	long long fac[n + 1], ans = 0;
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % m;
	for (int i = 1; i <= n; ++i) ans = (ans + fac[i] * fac[n - i + 1] % m * (n - i + 1) % m) % m;
	printf("%lld", ans);
	return 0;
}