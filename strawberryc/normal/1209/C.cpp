#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

const int N = 2e5 + 5;

int n, ans[N];
char s[N];

void work()
{
	int x = -1;
	read(n);
	scanf("%s", s + 1);
	for (int i = 1; i < n; i++) if (s[i] > s[i + 1]) {x = i + 1; break;}
	if (x == -1)
	{
		for (int i = 1; i <= n; i++) putchar('1');
		return (void) puts("");
	}
	char now1 = s[x], now2 = s[x - 1], m2 = ' '; ans[x] = 1;
	for (int i = 1; i < x; i++)
		if (s[i] <= s[x]) ans[i] = 1;
		else
		{
			ans[i] = 2;
			if (m2 == ' ') m2 = s[i];
		}
	for (int i = x + 1; i <= n; i++)
		if (s[i] >= now2) now2 = s[i], ans[i] = 2;
		else if (s[i] >= now1)
		{
			if (s[i] > m2) return (void) puts("-");
			now1 = s[i]; ans[i] = 1;
		}
		else return (void) puts("-");
	for (int i = 1; i <= n; i++) printf("%d", ans[i]);
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}