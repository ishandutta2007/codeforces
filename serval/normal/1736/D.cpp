#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
char s[N];
int p[N], cnt;

void solve()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	cnt = 0;
	for (int i = 1; i <= 2 * n; i += 2)
		if (s[i] != s[i + 1])
			p[++cnt] = i;
	if (cnt % 2 != 0)
	{
		printf("-1\n");
		return;
	}
	if (cnt == 0)
		printf("0\n");
	else
	{
		printf("%d", cnt);
		for (int i = 1; i <= cnt; i++)
			if (s[p[i]] - '0' == i % 2)
				printf(" %d", p[i]);
			else
				printf(" %d", p[i] + 1);
		printf("\n");
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", 2 * i - 1, " \n"[i == n]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}