#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, k;
char s[N];
char mx;

void solve()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	mx = 'a';
	for (int i = 1; i <= n; i++)
	{
		if (!k)
			break;
		int p = s[i] - mx;
		if (p <= 0)
			continue;
		p = min(p, k);
		char cur = s[i];
		char tar = (s[i] - p <= mx ? 'a' : s[i] - p);
		for (int j = 1; j <= n; j++)
			if (s[j] <= cur && s[j] > mx)
				s[j] = min(s[j], tar);
		k -= p;
		mx = cur;
	}
	printf("%s\n", s + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}