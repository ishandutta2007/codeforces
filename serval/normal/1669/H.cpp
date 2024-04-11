#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n, k;
int a[N], cnt[32];
int ans;

void solve()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < 32; i++)
		cnt[i] = n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		for (int j = 0; j <= 30; j++)
			if (a[i] & (1 << j))
				cnt[j]--;
	}
	ans = 0;
	for (int i = 30; i >= 0; i--)
		if (k >= cnt[i])
		{
			ans |= 1 << i;
			k -= cnt[i];
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