#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 1e5 + 5;

int n, ans, res[27], xnew[26], st[26], ed[26];
char s[N];

int main()
{
	int len;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		len = strlen(s + 1);
		memset(xnew, 0, sizeof(xnew));
		memset(st, 0, sizeof(st));
		memset(ed, 0, sizeof(ed));
		for (int j = 1; j <= len; j++)
		{
			if (s[j] != s[1]) break;
			st[s[1] - 'a'] = j;
		}
		for (int j = len; j >= 1; j--)
		{
			if (s[j] != s[len]) break;
			ed[s[len] - 'a'] = len - j + 1;
		}
		int tmp;
		for (int j = 1; j <= len; j++)
		{
			if (j == 1 || s[j] != s[j - 1]) tmp = 1;
			else tmp++;
			xnew[s[j] - 'a'] = std::max(xnew[s[j] - 'a'], tmp);
		}
		if (xnew[s[1] - 'a'] == len)
			for (int c = 0; c < 26; c++)
			{
				if (s[1] - 'a' == c)
				{
					if (res[c]) xnew[c] = res[c] + (res[c] + 1) * len;
				}
				else xnew[c] = res[c] ? 1 : 0;
			}
		else for (int c = 0; c < 26; c++)
			xnew[c] = std::max(xnew[c], res[c] ? 1 + st[c] + ed[c] : 0);
		for (int c = 0; c < 26; c++) res[c] = xnew[c];
	}
	for (int c = 0; c < 26; c++)
		ans = std::max(ans, res[c]);
	std::cout << ans << std::endl;
	return 0;
}