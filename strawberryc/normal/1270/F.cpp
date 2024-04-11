#include <bits/stdc++.h>

typedef long long ll;

const int N = 2e5 + 5;

int n, S, a[N], top, stk[N];
ll ans, sum[N];
char s[N];

int main()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	S = sqrt(n);
	for (int d = 1; d <= S; d++)
	{
		for (int i = 1; i <= n; i++) a[i] = 1 - (s[i] == '1' ? d : 0);
		sum[0] = 0;
		for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
		std::sort(sum, sum + n + 1);
		for (int i = 0; i <= n;)
		{
			int j = i;
			while (j <= n && sum[i] == sum[j]) j++;
			ans += 1ll * (j - i) * (j - i - 1) >> 1;
			i = j;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '1') stk[++top] = i;
		for (int j = 1; j <= S && j <= top; j++)
		{
			int l = i - stk[top - j + 1] + 1, r = i - stk[top - j];
			if (l < j * (S + 1)) l = j * (S + 1);
			if (l > r) continue;
			ans += r / j - (l - 1) / j;
		}
	}
	return std::cout << ans << std::endl, 0;
}