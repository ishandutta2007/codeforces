#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		a[i] = 0;
	for (int i = 1, j = 1; i + 3 <= n; i += 4, j += 2)
	{
		a[i] = j;
		a[i + 1] = j ^ (1 << 20);
		a[i + 2] = (j + 1);
		a[i + 3] = (j + 1) ^ (1 << 20);
	}
	if (n & 2)
	{
		int las = max(1, n / 4 * 4);
		a[las + 1] |= (1 << 21);
		a[las + 2] |= (1 << 22);
		a[las] |= (1 << 21) ^ (1 << 22);
	}
	if (n & 1)
	{
		a[n] |= (1 << 24);
		a[n - 1] |= (1 << 24);
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