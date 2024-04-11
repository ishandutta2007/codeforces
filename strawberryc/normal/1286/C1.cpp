#include <bits/stdc++.h>

const int N = 105;

int n, m, sum[N][26], tot[N], cw[N][2], cur[26];
char s[N], ans[N];

int main()
{
	std::cin >> n;
	printf("? %d %d\n", 1, n); fflush(stdout);
	for (int i = 1; i <= n * (n + 1) / 2; i++)
	{
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		for (int j = 1; j <= len; j++)
			sum[len][s[j] - 'a']++;
	}
	m = n >> 1;
	for (int i = 1; i <= m - ((n & 1) ^ 1); i++)
	{
		for (int c = 0; c < 26; c++) cur[c] = sum[i + 1][c];
		for (int j = 1; j < i; j++) cur[cw[j][0]] += i - j + 1,
			cur[cw[j][1]] += i - j + 1;
		for (int c = 0; c < 26; c++) cur[c] = sum[1][c] * (i + 1) - cur[c];
		for (int c = 0; c < 26; c++) while (cur[c]--) cw[i][tot[i]++] = c;
	}
	for (int c = 0; c < 26; c++) cur[c] = sum[1][c];
	for (int i = 1; i <= m - ((n & 1) ^ 1); i++) cur[cw[i][0]]--, cur[cw[i][1]]--;
	for (int c = 0; c < 26; c++) while (cur[c]--)
		cw[m + (n & 1)][tot[m + (n & 1)]++] = c;
	if (n & 1) ans[m + 1] = cw[m + 1][0] + 'a';
	if (n == 1)
	{
		printf("! ");
		for (int i = 1; i <= n; i++) putchar(s[1]);
		return puts(""), 0;
	}
	printf("? %d %d\n", 1, m); fflush(stdout);
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= m * (m + 1) / 2; i++)
	{
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		for (int j = 1; j <= len; j++)
			sum[len][s[j] - 'a']++;
	}
	if (m > 1)
	{
		printf("? %d %d\n", 2, m); fflush(stdout);
		for (int i = 1; i <= m * (m - 1) / 2; i++)
		{
			scanf("%s", s + 1);
			int len = strlen(s + 1);
			for (int j = 1; j <= len; j++)
				sum[len][s[j] - 'a']--;
		}
	}
	for (int i = m; i >= 1; i--)
	{
		for (int c = 0; c < 26; c++) sum[i][c] -= sum[i - 1][c];
		for (int c = 0; c < 26; c++) if (sum[i][c]) ans[i] = c + 'a';
		ans[n - i + 1] = ans[i] == cw[i][0] + 'a' ? cw[i][1] + 'a'
			: cw[i][0] + 'a';
	}
	printf("! ");
	for (int i = 1; i <= n; i++) putchar(ans[i]);
	return puts(""), 0;
}