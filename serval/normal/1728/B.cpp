#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 105;

int n;
int a[N];

void solve()
{
	scanf("%d", &n);
	a[n] = n;
	a[n - 1] = n - 1;
	a[n - 2] = 1;
	if (n & 1)
	{
		for (int i = 1; i < n - 3; i++)
			a[i] = n - i - 2;
		a[n - 3] = n - 2;
	}
	else
	{
		for (int i = 1; i < n - 2; i++)
			a[i] = n - i - 1;
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", a[i], " \n"[i == n]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}