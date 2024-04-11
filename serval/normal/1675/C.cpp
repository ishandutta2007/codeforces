#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
char s[N];

void solve()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	int l1 = 1, f0 = len;
	for (int i = 1; s[i]; i++)
	{
		if (s[i] == '1')
			l1 = max(l1, i);
		if (s[i] == '0')
			f0 = min(f0, i);
	}
	printf("%d\n", f0 - l1 + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}