#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#define fo(p, q, r) for(p = (q); p <= (r); ++p)
#define fow(p, q, r) for(p = (q); p >= (r); --p)
#define arclr(p, q) memset(p, (q), sizeof(p))
#define ll long long
using namespace std;

int cnt[35];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		ll x;
		scanf("%lld", &x);
		for(int i = 0; i <= 30; ++i) cnt[i] = 0;
		ll len;
		for(len = 2; len <= 30; ++len)
		{
			++cnt[x % len];
			x /= len;
			if (!x) break;
		}
		ll num = 0, ans = 1;
		for(int i = len - 1; i >= 1; --i)
		{
			for(int j = 1; j <= cnt[i]; ++j)
			{
				ans *= len - i - num;
				++num;
				ans /= j;
			}
		}
		ll tans = 1;
		num = 0;
		for(int i = len - 1; i >= 1; --i)
		{
			for(int j = 1; j <= cnt[i]; ++j)
			{
				tans *= len - i - num - 1;
				++num;
				tans /= j;
			}
		}
		printf("%lld\n", ans - tans - 1);
	}
}