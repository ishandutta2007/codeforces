#include <bits/stdc++.h>

typedef long long ll;

const int N = 1e5 + 5;

int n;
char s[N];
ll ans;

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int c = 0; c < 26; c++)
		for (int d = 0; d < 26; d++)
		{
			int cnt = 0; ll res = 0;
			for (int i = 1; i <= n; i++)
			{
				if (s[i] == d + 'a') res += cnt;
				if (s[i] == c + 'a') cnt++;
			}
			ans = std::max(ans, std::max(1ll * cnt, res));
		}
	return std::cout << ans << std::endl, 0;
}