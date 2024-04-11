#include <bits/stdc++.h>

using namespace std;

const int N = 100;

char s[N], t[N];

void solve()
{
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	int ls, lt;
	for (ls = 1; s[ls + 1]; ls++);
	for (lt = 1; t[lt + 1]; lt++);
	if (lt == 1 && t[1] == 'a')
	{
		printf("1\n");
		return;
	}
	for (int i = 1; i <= lt; i++)
		if (t[i] == 'a')
		{
			printf("-1\n");
			return;
		}
	long long ans = 1;
	for (int i = 1; i <= ls; i++)
		ans *= 2;
	printf("%lld\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}