#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
int ans;

int gcd(int x, int y)
{
	if (x % y == 0)
		return y;
	return gcd(y, x % y);
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ans = 1;
	for (int i = 2; i <= n - 1; i ++)
	{
		int aside = gcd(a[i - 1], a[i + 1]);
		if (a[i] % aside != 0)
			ans = 0;
	}
	if (ans)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}