#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, k;
int fac[N], inv[N];
int ans;

int fpw(int b, int e = mod - 2)
{
	if (e == 0)
		return 1;
	int ret = fpw(b, e >> 1);
	ret = 1ll * ret * ret % mod;
	if (e & 1)
		ret = 1ll * ret * b % mod;
	return ret;
}

int C(int n, int m)
{
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main()
{
	scanf("%d%d", &n, &k);
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[n] = fpw(fac[n]);
	for (int i = n; i; i--)
		inv[i - 1] = 1ll * inv[i] * i % mod;
	for (int i = 0; i <= k && i <= n; i++)
		ans = (ans + C(n, i)) % mod;
	printf("%d\n", ans);
	return 0;
}