#include <cstdio>

using namespace std;

const int N = 2e5 + 5;

int n, a, b;
int x[N];
long long pre[N];
long long ans;

void solve()
{
	ans = 0;
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
		pre[i] = pre[i - 1] + x[i];
	}
	int cur = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += 1ll * b * (x[i] - cur);
		long long nomove = 1ll * b * (pre[n] - pre[i]) - 1ll * b * (n - i) * cur;
		long long move = 1ll * a * (x[i] - cur) + 1ll * b * (pre[n] - pre[i]) - 1ll * b * (n - i) * x[i];
		if (move <= nomove)
		{
			ans += 1ll * a * (x[i] - cur);
			cur = x[i];
		}
	}
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