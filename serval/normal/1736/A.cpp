#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 105;

int n;
int a[N], b[N];
int a0, a1, b0, b1;
int ans, cnt;

void solve()
{
	scanf("%d", &n);
	a0 = a1 = b0 = b1 = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == 0)
			a0++;
		else
			a1++;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		if (b[i] == 0)
			b0++;
		else
			b1++;
	}
	cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += a[i] != b[i];
	ans = min(abs(a0 - b0) + 1, cnt);
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