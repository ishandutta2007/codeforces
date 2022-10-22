#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 3e5 + 5, M = N << 2;

int n, p[N], pos[N], q[N], mins[M], sum[M];

void change(int l, int r, int pos, int v, int p)
{
	if (l == r) return (void) (mins[p] += v, sum[p] += v);
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, v, p2);
	else change(mid + 1, r, pos, v, p3);
	sum[p] = sum[p2] + sum[p3];
	mins[p] = Min(mins[p2], sum[p2] + mins[p3]);
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(p[i]), pos[p[i]] = i;
	for (int i = 1; i <= n; i++) read(q[i]);
	for (int i = 0, j = n + 1; i < n; i++)
	{
		while (Min(mins[1], 0) == n + 1 - j - i)
			change(1, n, pos[--j], 1, 1);
		printf("%d ", j);
		change(1, n, q[i + 1], -1, 1);
	}
	return puts(""), 0;
}