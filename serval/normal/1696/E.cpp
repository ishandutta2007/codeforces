#include <cstdio>

using namespace std;

const int N = 4e5 + 5;
const int mod = 1000000007;

int n;
int a[N];
int fac[N], inv[N];
int ans;

int fpw(int b, int e = mod - 2)
{
	if (e == 0) return 1;
	int ret = fpw(b, e >> 1);
	ret = 1ll * ret * ret % mod;
	if (e & 1) ret = 1ll * ret * b % mod;
	return ret;
}

int C(int n, int m)
{
	if (n < 0 || m < 0 || m > n)
		return 0;
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main()
{
	fac[0] = 1;
	for (int i = 1; i < N; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[N - 1] = fpw(fac[N - 1]);
	for (int i = N - 1; i; i--)
		inv[i - 1] = 1ll * inv[i] * i % mod;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i])
			ans = (ans + C(i + a[i], a[i] - 1)) % mod;
	}
	printf("%d\n", ans);
	return 0;
}