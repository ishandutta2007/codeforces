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

const int MAXN = 50005;

int n, m, siz[MAXN], l[MAXN][10], r[MAXN][10];
set <pii> s;

inline bool Win(int x, int y)
{
	for (int i = 0; i < m; i ++)
		if (r[x][i] > l[y][i])
			return true;
	return false;
}

inline void Insert(int x)
{
	siz[x] = 1;
	while (true)
	{
		auto it = s.lower_bound(mp(l[x][0], x));
		if (it != s.end() && Win(x, it -> yy))
		{
			for (int i = 0; i < m; i ++)
				l[x][i] = min(l[x][i], l[it -> yy][i]), r[x][i] = max(r[x][i], r[it -> yy][i]);
			siz[x] += siz[it -> yy];
			s.erase(it);
		}
		else
			break;
	}
	while (true)
	{
		auto it = s.lower_bound(mp(l[x][0], x));
		if (it != s.begin())
		{
			it --;
			if (Win(it -> yy, x))
			{
				for (int i = 0; i < m; i ++)
					l[x][i] = min(l[x][i], l[it -> yy][i]), r[x][i] = max(r[x][i], r[it -> yy][i]);
				siz[x] += siz[it -> yy];
				s.erase(it);
			}
			else
				break;
		}
		else
			break;
	}
	s.insert(mp(l[x][0], x));
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < m; j ++)
			l[i][j] = r[i][j] = Read();
	for (int i = 1; i <= n; i ++)
		Insert(i), printf("%d\n", siz[(-- s.end()) -> yy]);
	return 0;
}