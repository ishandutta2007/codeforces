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

const int N = 5e4 + 5;

int n, tot, ix[N], tat, iy[N];

struct point
{
	int x, y, z, id;
} a[N];

inline bool comp(point a, point b)
{
	return a.x < b.x || (a.x == b.x && (a.y < b.y || (a.y == b.y && a.z < b.z)));
}

void solve2(int l, int r)
{
	for (int i = l; i < r; i += 2) printf("%d %d\n", a[i].id, a[i + 1].id);
	if (r - l + 1 & 1) iy[++tat] = a[r].id;
}

void solve1(int l, int r)
{
	tat = 0;
	for (int i = l; i <= r;)
	{
		int j = i;
		while (j <= r && a[i].y == a[j].y) j++;
		solve2(i, j - 1);
		i = j;
	}
	for (int i = 1; i < tat; i += 2) printf("%d %d\n", iy[i], iy[i + 1]);
	if (tat & 1) ix[++tot] = iy[tat];
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i].x), read(a[i].y), read(a[i].z), a[i].id = i;
	std::sort(a + 1, a + n + 1, comp);
	for (int i = 1; i <= n;)
	{
		int j = i;
		while (j <= n && a[i].x == a[j].x) j++;
		solve1(i, j - 1);
		i = j;
	}
	for (int i = 1; i < tot; i += 2) printf("%d %d\n", ix[i], ix[i + 1]);
	return 0;
}