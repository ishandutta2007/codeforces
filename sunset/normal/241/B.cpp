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
const int MAXM = 1500005;
const int mod = 1e9 + 7;

int n, m, tot = 1, a[MAXN], siz[MAXM], nxt[MAXM][2], cnt[MAXM][30];

inline void Insert(int x)
{
	int cur = 1;
	for (int i = 29; ~i; i --)
	{
		if (!nxt[cur][x >> i & 1])
			nxt[cur][x >> i & 1] = ++ tot;
		cur = nxt[cur][x >> i & 1];
		siz[cur] ++;
		for (int j = 0; j < 30; j ++)
			cnt[cur][j] += x >> j & 1;
	}
}

inline int Query(int x, int val)
{
	int ret = 0, cur = 1;
	for (int i = 29; ~i; i --)
		if (val >> i & 1)
			cur = nxt[cur][!(x >> i & 1)];
		else
			ret += siz[nxt[cur][!(x >> i & 1)]], cur = nxt[cur][x >> i & 1];
	return ret + siz[cur];
}

inline int Chk(int val)
{
	unsigned ret = 0;
	for (int i = 1; i <= n; i ++)
		ret += Query(a[i], val);
	return ret + (val ? 0 : n) >> 1;
}

inline int Get(int x, int val)
{
	int ret = 0, cur = 1;
	for (int i = 29; ~i; i --)
		if (val >> i & 1)
			cur = nxt[cur][!(x >> i & 1)];
		else
		{
			int p = nxt[cur][!(x >> i & 1)];
			for (int j = 0; j < 30; j ++)
				if (x >> j & 1)
					ret = ((1LL << j) * (siz[p] - cnt[p][j]) + ret) % mod;
				else
					ret = ((1LL << j) * cnt[p][j] + ret) % mod;
			cur = nxt[cur][x >> i & 1];
		}
	for (int j = 0; j < 30; j ++)
		if (x >> j & 1)
			ret = ((1LL << j) * (siz[cur] - cnt[cur][j]) + ret) % mod;
		else
			ret = ((1LL << j) * cnt[cur][j] + ret) % mod;
	return ret;
}

inline int Solve(int val)
{
	int ret = 0;
	for (int i = 1; i <= n; i ++)
		ret = (ret + Get(a[i], val)) % mod;
	return 1LL * ret * (mod + 1) / 2 % mod;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= n; i ++)
		Insert(a[i] = Read());
	int l = 0, r = (1 << 30) - 1, ret = 0;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (Chk(mid) <= m)
			ret = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	int ans = (1LL * (ret - 1) * (m - Chk(ret)) + Solve(ret)) % mod;
	return printf("%d\n", ans), 0;
}