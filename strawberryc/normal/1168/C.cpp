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

const int N = 3e5 + 5, M = 20;

int n, q, a[N], pl[N][M], pr[N][M];
bool ans[N];

struct query
{
	int l, r, id;
} que[N], tmp[N];

void solve(int l, int r, int ql, int qr)
{
	if (l == r || ql > qr) return;
	int mid = l + r >> 1;
	for (int i = 0; i <= 19; i++)
		pl[mid][i] = ((a[mid] >> i) & 1) ? a[mid] : (1 << i),
		pr[mid + 1][i] = ((a[mid + 1] >> i) & 1) ? a[mid + 1] : (1 << i);
	for (int i = mid - 1; i >= l; i--)
	{
		int tmp = 0;
		for (int j = 0; j <= 19; j++)
			if ((a[i] >> j) & 1) tmp |= pl[i + 1][j];
		for (int j = 0; j <= 19; j++)
			pl[i][j] = ((a[i] >> j) & 1) ? tmp : pl[i + 1][j];
	}
	for (int i = mid + 2; i <= r; i++)
	{
		int tmp = 0;
		for (int j = 0; j <= 19; j++)
			if ((a[i] >> j) & 1) tmp |= pr[i - 1][j];
		for (int j = 0; j <= 19; j++)
			pr[i][j] = ((a[i] >> j) & 1) ? tmp : pr[i - 1][j];
	}
	int tot = ql - 1;
	for (int i = ql; i <= qr; i++)
		if (que[i].l <= mid && que[i].r > mid)
		{
			for (int j = 0; j <= 19; j++) if ((a[que[i].l] >> j) & 1)
				for (int k = 0; k <= 19; k++) if ((a[que[i].r] >> k) & 1)
					ans[que[i].id] |= (pl[que[i].l][j] & pr[que[i].r][k]) != 0;
			tmp[++tot] = que[i];
		}
	int x1 = tot, x2;
	for (int i = ql; i <= qr; i++)
		if (que[i].r <= mid) tmp[++tot] = que[i];
	x2 = tot;
	for (int i = ql; i <= qr; i++)
		if (que[i].l > mid) tmp[++tot] = que[i];
	for (int i = ql; i <= qr; i++) que[i] = tmp[i];
	solve(l, mid, x1 + 1, x2);
	solve(mid + 1, r, x2 + 1, qr);
}

int main()
{
	n = read(); q = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= q; i++)
		que[i].l = read(), que[i].r = read(), que[i].id = i;
	solve(1, n, 1, q);
	for (int i = 1; i <= q; i++)
		puts(ans[i] ? "Shi" : "Fou");
	return 0;
}