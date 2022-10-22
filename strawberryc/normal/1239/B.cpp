#include <bits/stdc++.h>

const int N = 6e5 + 5;

int n, sm[N], cnt, mins, pos, tot, a[N], ans, L, R;
char s[N], t[N];

int main()
{
	int sum = 0, c1 = 0, c2 = 0;
	std::cin >> n; mins = n + 1;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '(') c1++, sum++; else c2++, sum--;
		if (sum < mins) mins = sum, cnt = 1, pos = i;
		else if (sum == mins) cnt++; sm[i] = sum;
	}
	if (c1 != c2) return puts("0\n1 1"), 0;
	ans = cnt; L = R = 1;
	for (int i = 1; i <= n; i++) t[i] = s[(pos + i - 1) % n + 1];
	for (int i = 1; i <= n; i++) s[i] = t[i];
	for (int i = 1; i <= n; i++) sm[i] = sm[i - 1] + (s[i] == '(' ? 1 : -1);
	for (int i = 1; i <= n; i++) if (sm[i] == 0)
		a[++tot] = i;
	a[++tot] = n + 1;
	for (int i = 1; i <= tot; i++)
	{
		int l = a[i - 1] + 1, r = a[i];
		if (r == n + 1) r--; if (l > r) continue;
		int lt = -1, rt = -1;
		for (int j = r; j >= l; j--) if (s[j] == '(') lt = j;
		for (int j = l; j <= r; j++) if (s[j] == ')') rt = j;
		int rs = 0;
		if (lt != -1 && rt != -1 && lt < rt) for (int j = lt; j <= rt; j++)
			if (sm[j] == 1) rs++;
		if (rs > ans) ans = rs, L = lt, R = rt;
	}
	tot = 0;
	for (int i = 1; i <= n; i++) if (sm[i] == 0 || sm[i] == 1)
		a[++tot] = i;
	a[++tot] = n + 1;
	for (int i = 1; i <= tot; i++)
	{
		int l = a[i - 1] + 1, r = a[i];
		if (r == n + 1) r--; if (l > r) continue;
		int lt = -1, rt = -1;
		for (int j = r; j >= l; j--) if (s[j] == '(') lt = j;
		for (int j = l; j <= r; j++) if (s[j] == ')') rt = j;
		int rs = cnt;
		if (lt != -1 && rt != -1 && lt < rt) for (int j = lt; j <= rt; j++)
			if (sm[j] == 2) rs++;
		if (rs > ans) ans = rs, L = lt, R = rt;
	}
	std::cout << ans << std::endl <<
		(L + pos - 1) % n + 1 << " " << (R + pos - 1) % n + 1 << std::endl;
	return 0;
}