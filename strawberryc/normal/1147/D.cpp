#include <bits/stdc++.h>

const int N = 2005, ZZQ = 998244353;

int n, p2[N], ans, fa[N], top[N];
char s[N];

int cx(int x)
{
	if (fa[x] == x) return x;
	int y = cx(fa[x]); top[x] ^= top[fa[x]];
	fa[x] = y;
}

bool zm(int x, int y, int op)
{
	int ix = cx(x), iy = cx(y);
	if (ix != iy) return fa[iy] = ix, top[iy] = op ^ top[x] ^ top[y], 1;
	return top[x] ^ top[y] ^ (!op) & 1;
}

int solve(int st)
{
	for (int i = 1; i <= (n << 1); i++) fa[i] = i, top[i] = 0;
	for (int i = 1; (i << 1) <= n; i++) zm(i, n - i + 1, 0);
	for (int i = 1; (i << 1) <= n - st + 1; i++)
		zm(st + i - 1 + n, (n << 1) - i + 1, 0);
	for (int i = 1; i <= n; i++) if (s[i] != '?')
		if (!zm(i, i + n, s[i] - '0')) return 0;
	for (int i = 1; i < st - 1; i++)
		if (!zm(i + n, i + 1 + n, 0)) return 0;
	if (!zm(1, 1 + n, 1)) return 0;
	if (!zm(st - 1 + n, st + n, 1)) return 0;
	int cnt = 0;
	for (int i = 1; i <= (n << 1); i++) if (fa[i] == i) cnt++;
	return p2[cnt - 1];
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	p2[0] = 1;
	for (int i = 1; i <= (n << 1); i++)
		p2[i] = (p2[i - 1] << 1) % ZZQ;
	for (int i = 2; i <= n; i++)
		ans = (ans + solve(i)) % ZZQ;
	return std::cout << ans << std::endl, 0;
}