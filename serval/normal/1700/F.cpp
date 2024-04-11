#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;

int au[N], ad[N];
int bu[N], bd[N];

int up[N], uf[N], ul, ur;
int dp[N], df[N], dl, dr;

long long ans;

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &au[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &ad[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &bu[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &bd[i]);
	ul = dl = 1;
	for (int i = 1; i <= n; i++)
	{
		if (au[i])
		{
			if (ul <= ur && uf[ul] == 2)
			{
				ans += i - up[ul];
				ul++;
			}
			else
			{
				ur++;
				up[ur] = i;
				uf[ur] = 1;
			}
		}
		if (ad[i])
		{
			if (dl <= dr && df[dl] == 2)
			{
				ans += i - dp[dl];
				dl++;
			}
			else
			{
				dr++;
				dp[dr] = i;
				df[dr] = 1;
			}
		}
		if (bu[i])
		{
			if (ul <= ur && uf[ul] == 1)
			{
				ans += i - up[ul];
				ul++;
			}
			else
			{
				ur++;
				up[ur] = i;
				uf[ur] = 2;
			}
		}
		if (bd[i])
		{
			if (dl <= dr && df[dl] == 1)
			{
				ans += i - dp[dl];
				dl++;
			}
			else
			{
				dr++;
				dp[dr] = i;
				df[dr] = 2;
			}
		}
		while (ul <= ur && dl <= dr)
		{
			if (uf[ul] == df[dl])
				break;
			ans += abs(up[ul] - dp[dl]) + 1;
			ul++;
			dl++;
		}
	}
	if (ul <= ur || dl <= dr)
		ans = -1;
	printf("%lld\n", ans);
}

int main()
{
	int T;
	T = 1; //scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}