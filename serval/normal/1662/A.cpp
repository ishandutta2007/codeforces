#include <cstdio>
#include <algorithm>

using namespace std;

int mx[15];

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 10; i++)
		mx[i] = -1;
	for (int i = 1; i <= n; i++)
	{
		int b, d;
		scanf("%d%d", &b, &d);
		mx[d] = max(mx[d], b);
	}
	for (int i = 1; i <= 10; i++)
		if (mx[i] == -1)
		{
			printf("MOREPROBLEMS\n");
			return;
		}
	int ans = 0;
	for (int i = 1; i <= 10; i++)
		ans += mx[i];
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