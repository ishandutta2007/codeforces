#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 200015;

priority_queue <int, vector <int>, greater <int>> q;
int n, m, top, sta[15], x[MAXN], y[MAXN];

struct Seg
{
	int val[MAXN << 2];

	inline void Modify(int p, int v)
	{
		for (p += 1 << 18, val[p] = v; p ^ 1; p >>= 1, val[p] = max(val[p << 1], val[p << 1 | 1]));
	}

	inline int Query(int p)
	{
		int ret = 0;
		for (p += 1 << 18; p; p >>= 1)
			if (!(p & 1))
				ret = max(ret, val[p ^ 1]);
		return ret;
	}
} seg_x, seg_y;

inline void Add(int p, int v)
{
	x[p] = v, y[v] = p, q.push(p);
	for (int i = v - 10; i <= v; i ++)
		if (y[i])
			sta[++ top] = y[i], seg_x.Modify(y[i], 0);
	while (top)
	{
		int x = sta[top --], y = ::x[x], t = seg_x.Query(x) + 1;
		seg_x.Modify(x, t), seg_y.Modify(y, t);
	}
}

inline void Del(int p)
{
	while (p --)
	{
		int x = q.top(), y = ::x[x]; q.pop();
		sta[++ top] = x, seg_x.Modify(x, 0), seg_y.Modify(y, 0);
	}
	int x = sta[top --], y = ::x[x], t;
	::x[x] = ::y[y] = 0;
	while (top)
		x = sta[top --], y = ::x[x], t = seg_y.Query(y) + 1, seg_x.Modify(x, t), seg_y.Modify(y, t), q.push(x);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1, p, v; i <= m; printf("%d\n", seg_x.Query(0)), i ++)
		if (Read() == 1)
			p = Read(), v = Read() + m - i, Add(p, v);
		else
			Del(Read());
	return 0;
}