#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int n;
int f[N], p[N], pw[N];
int ans;

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		f[i] = i - 1;
	for (int i = 1; i <= n; i++)
		for (int j = 2; j * i <= n; j++)
			f[j * i] -= f[i];
	for (int i = 1; i <= n; i++)
	{
		p[i] = (p[i - 1] + f[i]) % mod;
		pw[i] = (pw[i - 1] + 1ll * f[i] * i) % mod;
	}
	for (int d = 1; d <= n; d++)
		if (n % d == 0)
			for (int k = 1; d * k <= n; k++)
			{
				if (gcd(n / d, k) != 1)
					continue;
				ans = (ans + 1ll * p[n / k / d] * k % mod * n + mod - 1ll * pw[n / k / d] * k % mod * k % mod * d % mod) % mod;
			}
	printf("%d\n", ans);
	return 0;
}