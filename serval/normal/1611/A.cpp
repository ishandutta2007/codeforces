#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int n;

void solve()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	if (s[n] & 1 ^ 1)
	{
		printf("0\n");
		return;
	}
	if (s[1] & 1 ^ 1)
	{
		printf("1\n");
		return;
	}
	for (int i = 1; i <= n; i++)
		if (s[i] & 1 ^ 1)
		{
			printf("2\n");
			return;
		}
	printf("-1\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}