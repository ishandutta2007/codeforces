#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

// 0830
//

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 2e5 + 5, M = N << 2;

int n, q;
char s[N];

struct elem
{
	int c1, c2, pre1, suf1, pre2, suf2, dis;
	
	friend inline elem operator + (elem l, elem r)
	{
		return (elem) {r.c1 + Max(l.c1 - r.c2, 0),
		l.c2 + Max(r.c2 - l.c1, 0),
		Max(l.pre1, Max(l.c1 + l.c2 + r.pre2, l.c2 + r.pre1 - l.c1)),
		Max(r.suf1, Max(r.c1 + r.c2 + l.suf2, r.c1 + l.suf1 - r.c2)),
		Max(l.pre2, r.pre2 + l.c1 - l.c2), Max(r.suf2, l.suf2 + r.c2 - r.c1),
		Max(Max(l.dis, r.dis), Max(l.suf1 + r.pre2, r.pre1 + l.suf2))};
	}
} T[M];

elem __reset(char c)
{
	if (c == '(') return (elem) {1, 0, 1, 1, 1, -1, 1};
	else return (elem) {0, 1, 1, 1, -1, 1, 1};
}

void build(int l, int r, int p)
{
	if (l == r) return (void) (T[p] = __reset(s[l]));
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	T[p] = T[p2] + T[p3];
}

void change(int l, int r, int pos, char c, int p)
{
	if (l == r) return (void) (T[p] = __reset(c), s[pos] = c);
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, c, p2);
	else change(mid + 1, r, pos, c, p3);
	T[p] = T[p2] + T[p3];
}

int main()
{
	n = read(); q = read();
	scanf("%s", s + 1);
	n = n - 1 << 1;
	build(1, n, 1);
	std::cout << T[1].dis << std::endl;
	while (q--)
	{
		int x = read(), y = read();
		if (x == y)
		{
			printf("%d\n", T[1].dis);
			continue;
		}
		char cx = s[x], cy = s[y];
		change(1, n, x, cy, 1);
		change(1, n, y, cx, 1);
		printf("%d\n", T[1].dis);
	}
	return 0;
}