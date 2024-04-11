#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

char s[N];

void solve()
{
	int n;
	scanf("%s", s + 1);
	for (n = 1; s[n + 1]; n++);
	int ans = 1;
	for (int i = 1; i <= n; i++)
	{
		int j = i;
		while (j < n && s[j + 1] == s[i])
			j++;
		ans &= (i != j);
		i = j;
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