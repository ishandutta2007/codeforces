#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];

void solve()
{
	int c0 = 0, c1 = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] & 1)
			c1++;
		else
			c0++;
	}
	printf("%d\n", min(c0, c1));
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}