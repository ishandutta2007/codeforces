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

LL L, R;
vector <int> lb, rb;
int ans, cnt[10], cur[10];

inline bool Chk(int x, bool l, bool r)
{
	if (x == rb.size())
		return true;
	int L = lb[x], R = rb[x];
	if (l && r)
	{
		if (L == R)
		{
			if (cnt[L])
			{
				cnt[L] --;
				if (Chk(x + 1, 1, 1))
					return true;
				cnt[L] ++;
			}
			return false;
		}
		for (int i = L + 1; i <= R - 1; i ++)
			if (cnt[i])
				return true;
		if (cnt[L])
		{
			cnt[L] --;
			if (Chk(x + 1, 1, 0))
				return true;
			cnt[L] ++;
		}
		if (cnt[R])
		{
			cnt[R] --;
			if (Chk(x + 1, 0, 1))
				return true;
			cnt[R] ++;
		}
		return false;
	}
	else if (l)
	{
		for (int i = 9; i > L; i --)
			if (cnt[i])
				return true;
		if (cnt[L])
		{
			cnt[L] --;
			if (Chk(x + 1, 1, 0))
				return true;
			cnt[L] ++;
		}
		return false;
	}
	else if (r)
	{
		for (int i = 0; i < R; i ++)
			if (cnt[i])
				return true;
		if (cnt[R])
		{
			cnt[R] --;
			if (Chk(x + 1, 0, 1))
				return true;
			cnt[R] ++;
		}
		return false;
	}
}

inline void Dfs(int x, int ret)
{
	if (x == 10)
	{
		mcpy(cnt, cur);
		cnt[0] = ret;
		if (Chk(0, 1, 1))
			ans ++;
		return ;
	}
	for (int i = 0; i <= ret; i ++)
		cur[x] = i, Dfs(x + 1, ret - i);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	cin >> L >> R;
	while (L)
		lb.pb(L % 10), L /= 10;
	while (R)
		rb.pb(R % 10), R /= 10;
	while (lb.size() < rb.size())
		lb.pb(0);
	reverse(lb.begin(), lb.end());
	reverse(rb.begin(), rb.end());
	Dfs(1, rb.size());
	return printf("%d\n", ans), 0;
}