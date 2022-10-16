#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
char s[N];

void solve()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == 'W')
			continue;
		int r = i;
		while (r < n && s[r + 1] != 'W')
			r++;
		int B = 0, R = 0;
		for (int j = i; j <= r; j++)
		{
			B |= s[j] == 'B';
			R |= s[j] == 'R';
		}
		if (i == r)
			ans = 0;
		if (B == 0 || R == 0)
			ans = 0;
		i = r;
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