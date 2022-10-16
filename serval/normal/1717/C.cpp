#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
int b[N], lim[N];
int ans;

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
		lim[i] = (b[i] > b[i % n + 1] + 1);
	ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans &= a[i] <= b[i];
		if (lim[i])
			ans &= a[i] == b[i];
	}
	printf("%s\n", ans ? "YES" : "NO");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}