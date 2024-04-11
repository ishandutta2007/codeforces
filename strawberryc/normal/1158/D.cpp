#include <bits/stdc++.h>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

typedef long long ll;

const int N = 5005;

int n, ans[N];
char s[N];
bool vis[N];

struct point
{
	int x, y;
	
	friend inline point operator - (point a, point b)
	{
		return (point) {b.x - a.x, b.y - a.y};
	}
	
	friend inline ll operator * (point a, point b)
	{
		return 1ll * a.x * b.y - 1ll * a.y * b.x;
	}
} a[N];

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		a[i].x = read(), a[i].y = read();
	scanf("%s", s + 1);
	ans[1] = 1;
	for (int i = 1; i <= n; i++)
		if (a[i].x < a[ans[1]].x || (a[i].x == a[ans[1]].x
			&& a[i].y == a[ans[1]].y))
				ans[1] = i;
	vis[ans[1]] = 1;
	for (int i = 1; i <= n - 2; i++)
	{
		int ri = 0; point cent = a[ans[i]];
		for (int j = 1; j <= n; j++)
			if (!vis[j] && (!ri || (((cent - a[ri]) * (cent - a[j]) < 0)
				^ (s[i] == 'R')))) ri = j;
		vis[ans[i + 1] = ri] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {ans[n] = i; break;}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return puts(""), 0;
}