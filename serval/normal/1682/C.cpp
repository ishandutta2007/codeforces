#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
int b[N], cnt;
int pre[N], suf[N];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != a[i - 1])
			b[++cnt] = 0;
		b[cnt]++;
	}
	int ans = 0;
	pre[0] = suf[cnt + 1] = 0;
	for (int i = 1; i <= cnt; i++)
		pre[i] = pre[i - 1] + (b[i] > 1);
	for (int i = cnt; i; i--)
		suf[i] = suf[i + 1] + (b[i] > 1);
	for (int i = 1; i <= cnt; i++)
	{
		pre[i] += (i - pre[i]) / 2;
		suf[i] += (cnt - i - suf[i]) / 2;
	}
	for (int i = 1; i <= cnt; i++)
		ans = max(ans, 1 + pre[i - 1] + suf[i + 1]);
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