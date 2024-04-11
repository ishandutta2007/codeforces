#include <bits/stdc++.h>

// 20030830

const int N = 5e5 + 5;

int n, m, tt, cnt1, cnt0, c0, c1, nxt[N], s0[N], s1[N];
char s[N], t[N];

struct node
{
	int id, cst, ccc;
} a[N];

inline bool comp(node a, node b)
{
	return a.cst < b.cst || (a.cst == b.cst && a.ccc < b.ccc);
}

int main()
{
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	for (int i = 1; i <= n; i++)
		if (s[i] == '1') cnt1++;
		else cnt0++;
	for (int i = 1; i <= m; i++)
		if (t[i] == '1') c1++;
		else c0++;
	for (int i = 2, j = 0; i <= m; i++)
	{
		while (j && t[j + 1] != t[i]) j = nxt[j];
		if (t[j + 1] == t[i]) j++;
		nxt[i] = j;
	}
	if (cnt1 < c1 || cnt0 < c0)
	{
		for (int i = 1; i <= n; i++) putchar(s[i]);
		return puts(""), 0;
	}
	for (int i = m; i >= 1; i--)
		if (t[i] == '1') s1[i] = s1[i + 1] + 1, s0[i] = s0[i + 1];
		else s1[i] = s1[i + 1], s0[i] = s0[i + 1] + 1;
	for (int i = nxt[m]; ; i = nxt[i])
	{
		a[++tt] = (node) {i + 1, s0[i + 1], s1[i + 1]};
		if (!i) break;
	}
	for (int i = 1; i <= m; i++) putchar(t[i]);
	int tql = cnt0 - c0, trl = cnt1 - c1;
	std::sort(a + 1, a + tt + 1, comp);
	while (a[1].cst <= tql && a[1].ccc <= trl)
	{
		tql -= a[1].cst, trl -= a[1].ccc;
		for (int j = a[1].id; j <= m; j++) putchar(t[j]);
	}
	while (tql--) putchar('0');
	while (trl--) putchar('1');
	puts("");
	return 0;
}