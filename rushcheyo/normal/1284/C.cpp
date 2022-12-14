#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, P, fac[250005];

int main() {
	scanf("%d%d", &n, &P);
	for (int i = fac[0] = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	int ans = 0;
	for (int l = 1; l <= n; ++l)
		ans = (ans + 1ll * (n - l + 1) * fac[l] % P * fac[n - l + 1]) % P;
	printf("%d\n", ans);
	return 0;
}