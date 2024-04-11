#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

long long p[N], s[N];
long long x[N];
long long ans;

int n, m;

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &p[i]);
		s[i] = s[i - 1] + p[i];
	}
	for (int i = 1; i <= m; i++)
		scanf("%lld", &x[i]);
	sort(x + 1, x + m + 1);
	ans = 0;
	if (x[1] > 0)
		ans = max(ans, s[min((x[1] + 99) / 100, (long long)n)]);
	if (x[m] < (n - 1) * 100)
		ans = max(ans, s[n] - s[x[m] / 100 + 1]);
	for (int i = 1; i < m; i++)
	{
		long long L = x[i], R = x[i + 1];
		long long l = L / 100 + 2, r = (R - 1) / 100 + 1;
		long long d = x[i + 1] - x[i];
		d = (d - 1) / 2;
		d = d / 100;
		for (int j = l; j + d <= n && j + d <= r; j++)
			ans = max(ans, s[j + d] - s[j - 1]);
	}
	printf("%lld\n", ans);
}

int main()
{
	int T = 1;
	//scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}