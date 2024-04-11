#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 25;

int n;
int a[N];

void solve()
{
	scanf("%d", &n);
	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > a[ans])
			ans = i;
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