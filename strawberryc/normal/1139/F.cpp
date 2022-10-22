#include <bits/stdc++.h>

// 20030830

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 1e5 + 5, M = N << 2;

int n, m, p[N], s[N], b[N], inc[N], pref[N], tot, a[M], A[M], B[M], cnt, ans[N];

struct node
{
	int tm, x, y, op, id;
} que[M];

inline bool comp(node a, node b)
{
	return a.tm < b.tm || (a.tm == b.tm && a.op < b.op);
}

void changeA(int x, int v)
{
	for (; x <= tot; x += x & -x)
		A[x] += v;
}

int askA(int x)
{
	int res = 0;
	for (; x; x -= x & -x)
		res += A[x];
	return res;
}

void changeB(int x, int v)
{
	for (; x <= tot; x += x & -x)
		B[x] += v;
}

int askB(int x)
{
	int res = 0;
	for (; x; x -= x & -x)
		res += B[x];
	return res;
}

int main()
{
	n = read(); m = read();
	for (int i = 1; i <= n; i++) p[i] = read();
	for (int i = 1; i <= n; i++) s[i] = read();
	for (int i = 1; i <= n; i++) b[i] = read();
	for (int i = 1; i <= m; i++) inc[i] = read();
	for (int i = 1; i <= m; i++) pref[i] = read();
	for (int i = 1; i <= n; i++)
		a[++tot] = p[i] + b[i], a[++tot] = b[i] - p[i] + 1;
	for (int i = 1; i <= m; i++)
		a[++tot] = inc[i] + pref[i], a[++tot] = pref[i] - inc[i];
	std::sort(a + 1, a + tot + 1);
	int tt = std::unique(a + 1, a + tot + 1) - a - 1;
	tot = tt;
	for (int i = 1; i <= n; i++)
		que[++cnt] = (node) {p[i], p[i], b[i], 1, 0},
		que[++cnt] = (node) {s[i] + 1, p[i], b[i], -1, 0};
	for (int i = 1; i <= m; i++)
		que[++cnt] = (node) {inc[i], inc[i], pref[i], 2, i};
	std::sort(que + 1, que + cnt + 1, comp);
	for (int i = 1; i <= cnt; i++)
		if (que[i].op <= 1)
		{
			changeA(std::lower_bound(a + 1, a + tot + 1,
				que[i].x + que[i].y) - a, que[i].op);
			changeB(std::lower_bound(a + 1, a + tot + 1,
				que[i].y - que[i].x + 1) - a, que[i].op);
		}
		else ans[que[i].id] = askA(std::lower_bound(a + 1, a + tot + 1,
			que[i].x + que[i].y) - a) -
			askB(std::lower_bound(a + 1, a + tot + 1,
			que[i].y - que[i].x) - a);
	for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
	return puts(""), 0;
}