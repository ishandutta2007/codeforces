#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
long long a[N], d[N];
long long ans;

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		d[i] = a[i] - a[i - 1];
	}
	ans = 0;
	for (int i = 2; i <= n; i++)
		if (d[i] < 0)
		{
			ans += -d[i];
			d[1] += d[i];
			d[i] = 0;
		}
	if (d[1] > 0)
	{
		ans += d[1];
		d[1] = 0;
	}
	for (int i = 1; i <= n; i++)
		ans += abs(d[i]);
	printf("%lld\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}