#include <bits/stdc++.h>

using namespace std;

const int N = 35;

int n;
int a[N];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int ans = 0;
	for (int i = 1; i <= 32 * n; i++)
	{
		int j;
		for (j = n; j > 1; j--)
			if (a[j - 1] >= a[j])
			{
				a[j - 1] >>= 1;
				break;
			}
		if (j == 1)
			break;
		ans++;
	}
	for (int j = 1; j < n; j++)
		if (a[j] >= a[j + 1])
		{
			printf("-1\n");
			return;
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