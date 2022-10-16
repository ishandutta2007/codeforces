#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;

int n, s;
int a[N], pre[N];
int ans;

void solve()
{
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] + a[i];
	}
	if (pre[n] < s)
	{
		printf("-1\n");
		return;
	}
	ans = n;
	int l = 0;
	for (int i = 1; i <= n; i++)
	{
		if (pre[i] - pre[l] < s)
			continue;
		while (pre[i] - pre[l] > s)
			l++;
		if (pre[i] - pre[l] == s)
			ans = min(ans, n - (i - l));
	}
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}