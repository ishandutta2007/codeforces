#include <bits/stdc++.h>

using namespace std;

char s[110][110];
long long a[110];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] == '#')a[i] |= 1ll << (j - 1);
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			if(((a[i] & a[j]) != 0) && (a[i] != a[j]))
			{
				puts("No");
				return 0;
			}
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] == '#')a[j] |= 1ll << (i - 1);
	for(int i = 1; i <= m; i++)
		for(int j = i + 1; j <= m; j++)
			if(((a[i] & a[j]) != 0) && (a[i] != a[j]))
			{
				puts("No");
				return 0;
			}
	puts("Yes");
}