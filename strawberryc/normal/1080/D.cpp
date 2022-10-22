#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Rof(i, a, b) for (i = a; i >= b; i--)

const int N = 40;

typedef long long ll;

int n;
ll k, f[N], g[N], p2[N];

bool greaters(ll a, ll b, ll c)
{
	if (c < 0) return 0;
	if (!b) return a * b < 0;
	return a < (c + b - 1) / b;
}

void work()
{
	int i, j;
	ll delta;
	std::cin >> n >> k;
	if (n > 31) return (void) printf("YES %d\n", n - 1);
	Rof (i, n - 1, 0)
	{
		if (f[n - i] > k) continue;
		ll grids = 1ll * (p2[n - i] - 1) * (p2[n - i] - 1);
		if (greaters(g[i], grids, k - g[n - i])) continue;
		return (void) printf("YES %d\n", i);
	}
	puts("NO");
}

int main()
{
	int i, j, T; std::cin >> T;
	f[1] = p2[0] = g[1] = 1;
	For (i, 1, 35) p2[i] = 2ll * p2[i - 1];
	For (i, 2, 35) f[i] = 3ll * f[i - 1] + 1,
		g[i] = 4ll * g[i - 1] + 1;
	while (T--) work();
	return 0;
}