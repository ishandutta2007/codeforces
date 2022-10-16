#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
char s[N];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		scanf("%s", s + 1);
		for (int j = 1; j <= k; j++)
			if (s[j] == 'U')
				(a[i] += 9) %= 10;
			else
				(a[i] += 1) %= 10;
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