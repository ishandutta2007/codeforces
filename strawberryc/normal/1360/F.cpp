#include <bits/stdc++.h>

const int N = 15;

int n, m;
char ans[N], s[N][N];

bool check()
{
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= m; j++) if (s[i][j] != ans[j]) cnt++;
		if (cnt > 1) return 0;
	}
	return 1;
}

void output()
{
	for (int i = 1; i <= m; i++) putchar(ans[i]);
	puts("");
}

void work()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) ans[j] = s[i][j];
		if (check()) return output();
		for (int j = 1; j <= m; j++)
			for (int c = 0; c < 26; c++)
			{
				char tmp = ans[j]; ans[j] = c + 'a';
				if (check()) return output();
				ans[j] = tmp;
			}
	}
	puts("-1");
}

int main()
{
	int T; std::cin >> T;
	while (T--) work();
	return 0;
}