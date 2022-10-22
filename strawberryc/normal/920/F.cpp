#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define p2 p << 1
#define p3 p << 1 | 1

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

const int N = 3e5 + 5, MaxN = 1e6, M = 1e6 + 5, L = N << 2;

int n, m, a[N], pri[M], tot, d[M], ps[M];
bool mark[M], is1or2[L];
ll sum[L];

void sieve()
{
	int i, j;
	mark[0] = mark[d[1] = 1] = 1;
	For (i, 2, MaxN)
	{
		if (!mark[i]) d[pri[++tot] = i] = 2, ps[i] = 1;
		For (j, 1, tot)
		{
			if (1ll * i * pri[j] > MaxN) break;
			mark[i * pri[j]] = 1;
			if (i % pri[j] == 0)
			{
				d[i * pri[j]] = d[i] / (ps[i] + 1) * (ps[i] + 2);
				ps[i * pri[j]] = ps[i] + 1;
			}
			else d[i * pri[j]] = d[i] << 1, ps[i * pri[j]] = 1;
		}
	}
}

void build(int l, int r, int p)
{
	if (l == r)
		return (void) (sum[p] = a[l], is1or2[p] = a[l] == 1 || a[l] == 2);
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	sum[p] = sum[p2] + sum[p3];
	is1or2[p] = is1or2[p2] && is1or2[p3];
}

void change(int l, int r, int s, int e, int p)
{
	if (is1or2[p]) return;
	if (l == r)
	{
		sum[p] = d[sum[p]];
		return (void) (is1or2[p] = sum[p] == 1 || sum[p] == 2);
	}
	int mid = l + r >> 1;
	if (e <= mid) change(l, mid, s, e, p2);
	else if (s >= mid + 1) change(mid + 1, r, s, e, p3);
	else change(l, mid, s, mid, p2),
		change(mid + 1, r, mid + 1, e, p3);
	sum[p] = sum[p2] + sum[p3];
	is1or2[p] = is1or2[p2] && is1or2[p3];
}

ll ask(int l, int r, int s, int e, int p)
{
	if (l == s && r == e) return sum[p];
	int mid = l + r >> 1;
	if (e <= mid) return ask(l, mid, s, e, p2);
	else if (s >= mid + 1) return ask(mid + 1, r, s, e, p3);
	else return ask(l, mid, s, mid, p2) +
		ask(mid + 1, r, mid + 1, e, p3);
}

int main()
{
	int i, op, l, r;
	n = read(); m = read();
	For (i, 1, n) a[i] = read();
	sieve(); build(1, n, 1);
	while (m--)
	{
		op = read(); l = read(); r = read();
		if (op == 1) change(1, n, l, r, 1);
		else printf("%I64d\n", ask(1, n, l, r, 1));
	}
	return 0;
}