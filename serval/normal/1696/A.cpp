#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n, z;
int a[N];

int ans;

void solve()
{
	ans = 0;
	scanf("%d%d", &n, &z);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		ans = max(ans, a[i] | z);
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