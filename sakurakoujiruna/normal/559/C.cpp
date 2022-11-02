#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2011;
const int M = 200011;
typedef long long intl;
const intl Mod = (intl)1e9 + 7;

#define x first
#define y second

pair <int, int> p[N];
intl qpow(intl a, intl b)
{
	intl tmp = a;
	intl ret = 1;
	while(b > 0)
	{
		if(b & 1)
		{
			ret *= tmp;
			ret %= Mod;
		}
		tmp *= tmp;
		tmp %= Mod;
		b >>= 1;
	}
	return ret;
}

intl fac[M];
intl inv_fac[M];

intl c(int n, int m)
{
	return fac[n] * inv_fac[m] % Mod * inv_fac[n - m] % Mod;
}

intl dp[N];

int main()
{
	fac[0] = inv_fac[0] = 1;
	for(int i = 1; i < M; i ++)
	{
		fac[i] = fac[i - 1] * i % Mod;
		inv_fac[i] = inv_fac[i - 1] * qpow(i, Mod - 2) % Mod;
	}

	ios :: sync_with_stdio(false);
	int h, w, n;
	cin >> h >> w >> n;
	for(int i = 1; i <= n; i ++)
		cin >> p[i].x >> p[i].y;
	sort(p + 1, p + n + 1);

	intl ans = c(h + w - 2, h - 1);
	for(int i = 1; i <= n; i ++)
	{
		dp[i] = c(p[i].x + p[i].y - 2, p[i].y - 1);
		for(int j = 1; j < i; j ++)
			if(p[j].x <= p[i].x && p[j].y <= p[i].y)
			{
				dp[i] -= dp[j] * c(p[i].x - p[j].x + p[i].y - p[j].y, p[i].x - p[j].x);
				dp[i] %= Mod;
			}
		ans -= dp[i] * c(h - p[i].x + w - p[i].y, h - p[i].x);
		ans %= Mod;
	}
	cout << (ans + Mod) % Mod << '\n';
	return 0;
}