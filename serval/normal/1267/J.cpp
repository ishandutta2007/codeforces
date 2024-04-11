#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#define fo(p, q, r) for(p = (q); p <= (r); ++p)
#define fow(p, q, r) for(p = (q); p >= (r); --p)
#define arclr(p, q) memset(p, (q), sizeof(p))
using namespace std;

int cnt[2000005], flag[2000005];

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int x, m = 0;
		for(int i = 1; i <= n; ++i) cnt[i] = 0, flag[i] = 0;
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", &x);
			if (!flag[x])
				flag[x] = ++m;
			++cnt[flag[x]];
		}
		int mn = 2000005;
		for(int i = 1; i <= m; ++i)
			mn = min(mn, cnt[i]);
		int fir = (int)sqrt(mn);
		int ans = n;
		for(int i = fir + 1; i <= mn + 1; ++i)
		{
			int tans = 0, fl = 1;
			for(int j = 1; j <= m; ++j)
			{
				if (cnt[j] % i == 0) tans += cnt[j] / i;
				else 
					if (cnt[j] / i >= i - 1 - cnt[j] % i) tans += cnt[j] / i + 1;
					else 
					{
						fl = 0;
						break;
					}
			}
			if (fl) ans = min(ans, tans);
		}
		printf("%d\n", ans);
	}
}