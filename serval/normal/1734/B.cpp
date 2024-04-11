#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 505;

int n;

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			printf("%d%c", j == 1 || j == i ? 1 : 0, " \n"[j == i]);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}