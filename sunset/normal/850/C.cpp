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

const int MAXN = 105;
const int MAXM = 7000005;

int n, m, ans;
map <int, int> sg;
pii a[MAXM];

inline int F(int x)
{
	if (sg.find(x) != sg.end())
		return sg[x];
	if (x == 1)
		return 0;
	bool vis[45];
	mset(vis, 0);
	for (int i = 1; x >> i; i ++)
		vis[F(x >> i | (x & ((1 << i) - 1)))] = 1;
	for (int i = 0; ; i ++)
		if (!vis[i])
			return sg[x] = i;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	while (n --)
	{
		int x = Read();
		for (int i = 2; i * i <= x; i ++)
			if (x % i == 0)
			{
				int cnt = 0;
				while (x % i == 0)
					cnt ++, x /= i;
				a[++ m] = mp(i, cnt);
			}
		if (x ^ 1)
			a[++ m] = mp(x, 1);
	}
	sort(a + 1, a + m + 1);
	for (int l = 1, r = 1; l <= m; )
	{
		while (a[r].xx == a[l].xx)
			r ++;
		int cur = 0;
		while (l < r)
			cur |= 1 << a[l ++].yy;
		ans ^= F(cur);
	}
	return puts(ans ? "Mojtaba" : "Arpa"), 0;
}