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

const int MAXN = 300005;

int n, m, v[MAXN], ls[MAXN], b[MAXN], mx;
pii bit[MAXN][2], event[MAXN << 1];
set <int> cur;
vector <pii> ans;
map <pii, int> len;

inline int Lowbit(int x)
{
	return x & -x;
}

inline void Modify(int x, int v, int t)
{
	for (; x <= n; x += Lowbit(x))
		if (bit[x][0].yy == t)
			bit[x][0].xx = max(bit[x][0].xx, v);
		else if (bit[x][1].xx < v)
		{
			bit[x][1] = mp(v, t);
			if (bit[x][0] < bit[x][1])
				swap(bit[x][0], bit[x][1]);
		}
}

inline int Query(int x, int t)
{
	int ret = 0;
	for (; x; x -= Lowbit(x))
		if (bit[x][0].yy == t)
			ret = max(ret, bit[x][1].xx);
		else
			ret = max(ret, bit[x][0].xx);
	return ret;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	event[0] = mp(0, 0); event[1] = mp(2000000000, 0);
	for (int i = 1; i <= n; i ++)
	{
		int l = Read(), r = Read(); v[i] = ls[i] = Read();
		event[i << 1] = mp(l, i); event[i << 1 | 1] = mp(r, i);
	}
	sort(ls + 1, ls + n + 1);
	sort(event, event + (n + 1 << 1));
	if (event[0].yy)
		cur.insert(event[0].yy);
	for (int i = 1; i < n + 1 << 1; i ++)
	{
		int t = event[i].xx - event[i - 1].xx;
		if (t && cur.size() <= 2)
		{
			int p = 0, q = 0;
			if (cur.size() > 0)
				p = *cur.rbegin();
			if (cur.size() > 1)
				q = *cur.begin();
			int now = -1;
			if (!p)
				now = mx;
			else
			{
				if (!q)
				{
					if (v[p] <= m)
					{
						now = max(b[p], Query(upper_bound(ls + 1, ls + n + 1, m - v[p]) - ls - 1, p));
						Modify(lower_bound(ls + 1, ls + n + 1, v[p]) - ls, len[mp(p, 0)] + t, p);
					}
				}
				else if (v[p] + v[q] <= m)
				{
					now = len[mp(p, 0)] + len[mp(q, 0)];
					b[p] = max(b[p], len[mp(q, 0)] + len[mp(p, q)] + t);
					b[q] = max(b[q], len[mp(p, 0)] + len[mp(p, q)] + t);
				}
				if (~now)
					now += len[mp(p, q)] + len[mp(0, 0)];
			}
			if (~now && now + t > mx)
				mx = now + t, ans.pb(mp(mx, event[i].xx));
			len[mp(p, q)] += t;
		}
		if (event[i].yy)
			if (cur.find(event[i].yy) == cur.end())
				cur.insert(event[i].yy);
			else
				cur.erase(event[i].yy);
	}
	for (int Q = Read(), x; Q; Q --)
	{
		auto it = lower_bound(ans.begin(), ans.end(), mp(x = Read(), 0));
		printf("%d\n", it -> yy - (it -> xx - x));
	}
}