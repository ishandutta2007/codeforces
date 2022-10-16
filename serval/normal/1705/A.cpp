#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n, x;
int a[N];

void solve()
{
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= 2 * n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 2 * n + 1);
	for (int i = 1; i <= n; i++)
		if (a[i + n] - a[i] < x)
		{
			printf("NO\n");
			return;
		}
	printf("YES\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}